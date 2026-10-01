// xvideo_edit.cpp 
#include <iostream>
#include "xtask_factory.h"
#include "xvideo_input.h"
#include "xdir.h"
int main()
{
    {
        //XDir d;
        //auto files = d.GetFiles(".");
        //for (auto& f : files)
        //    cout << f.name << endl;
    }
    //auto fp = _popen("ffmpeg -y  -ss 10 -t 5 -i test.mp4 out.mp4  2>&1 ", "r");
    //char s[1024] = { 0 };
    //char c;
    //while (c = fgetc(fp))
    //{
    //    cout << c << flush;
    //    if (c == EOF)break;
    //}
    //
    //system("ffmpeg -y -i test.mp4 -encryption_key  0123456789ABCDEF0123456789ABCDEF -encryption_scheme cenc-aes-ctr -encryption_kid 0123456789ABCDEF0123456789ABCDEF  en.mp4");
    //system("ffmpeg -y -ss 10 -t 5 -i test.mp4 out.mp4 ");
    XVideoInput input;
    input.Start(XTaskFactory::Create());
    /*
    auto task = XTaskFactory::Create();
    XTask::Data data;
    data.src = "test.mp4";
    data.des = "out.mp4";
    data.type = "cv";
    task->Start(data);*/
    //system("ffplay test.mp4");
    //system("ffmpeg -y -i test.mp4 out.mp4 ");
}