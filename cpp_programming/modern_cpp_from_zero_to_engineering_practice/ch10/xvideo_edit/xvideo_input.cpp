#include "xvideo_input.h"
#include "user_input.h"
#include <iostream>
#include "xdir.h"

void XVideoInput::RunTask(XTask& task,
    const XTask::Data& data)
{
    task.Start(data);
    int p = 0;
    int l = -1;
    while (task.Runing())
    {
        p = task.Progress();
        if (p != l)
        {
            // flush is required: without it the \r updates stay buffered
            std::cout << "\r%" << task.Progress() << std::flush;
            l = p;
        }
    }
    std::cout << "\r%" << "100" << std::endl;
}
void XVideoInput::Start
(std::unique_ptr<XTask> task)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    UserInput user;
    XTask::Data data;
    // play test.mp4 
    // cv test.mp4 out.mp4
    user
        .RegTask("play", [&] {
        data.type = "play";
        task->Start(data);
        })
        .RegTask(
        "cv", [&] {
            std::cout << "cv task" << std::endl;
            std::cout << data.src << " "
                << data.des << std::endl;
            data.type = "cv";
            task->Clear();

            if (XDir::IsDir(data.src))
            {
                XDir dir;
                auto files = dir.GetFiles(data.src);
                for (auto f : files)
                {
                    XTask::Data d = data;
                    d.src = f.path;
                    if (!XDir::IsDir(data.des))
                    {
                        XDir::Create(data.des);
                    }
                    d.des = data.des + "/" + f.name;
                    task->Clear();
                    RunTask(*task, d);
                }
            }
            else
            {
                RunTask(*task, data);
            }

           
        }
    ).Reg("-s", [&] (const std::string &s){
            std::cout << "-s��" << s << std::endl;
            data.src = s;
        })

    .Reg("-d", [&](const std::string& s) {
    std::cout << "-d��" << s << std::endl;
    data.des = s;
        })

    .Reg("-b", [&](const std::string& s) {
    data.begin_sec = std::stoi(s);
        })

    .Reg("-e", [&](const std::string& s) {
            data.end_sec = std::stoi(s);
            })
    .Reg("-p", [&](const std::string& s) {
                if (s.empty())
                {
                    std::cout << "password:" << std::flush;
                    std::string pass;
                    std::cin >> pass;
                    data.password = pass;
                }else
                    data.password = s;
        })

        .Reg("-dp", [&](const std::string& s) {
                if (s.empty())
                {
                    std::cout << "password:" << std::flush;
                    std::string pass;
                    std::cin >> pass;
                    data.password = pass;
                }
                else
                    data.password = s;
                data.is_enc = false;
            })

            ;

    user.Start([&] (std::vector<std::string> para){
        std::cout << "init task" << std::endl;
        task->Clear();

        data = XTask::Data();
        // play test.mp4
        // cv test.mp4 out.mp4
        if (para.size() <  4)
        {
            if(para.size()>1)
                data.src = para[1];
            if (para.size() > 2)
                data.des = para[2];
        }

        });

}
