// test_xlog.cpp
#include <iostream>
#include "log_fac.h"
#include "xexec.h"
#include "user_input.h"

int main()
{

    {
        //cv -s test.mp4 -d test.avi
        UserInput user;
        user
            .Reg("-s", [](const std::string& s)
                {
                    std::cout << "----- src:" << s << std::endl;
                }
            )
            .Reg("-d", [](const std::string& s)
                {
                    std::cout << "----- des:" << s << std::endl;
                }
            )   
            .Reg("-p", [](const std::string& s)
                {
                    std::cout << "password:" << s << std::endl;
                }
                )
               .RegTask("cv", [] {std::cout << "@@@ cv task @@@!"
                   << std::endl; });
       
    ;

        user.Start();
        return 0;
    }
    XExec exec;
    exec.Start("ping 127.0.0.1 -t");

    std::string out;
    while (exec.Runing())
    {
        if (exec.GetOuput(out))
        {
            std::cout << out << std::endl;
        }
    }
    while (exec.GetOuput(out))
    {
        std::cout << out << std::endl;
    }

    exec.Wait();

    //cout << exec.Start("cd") << endl;
    return 0;
    XLOGINIT();
    LOGDEBUG("test xlog");

    std::cout << "Hello World!\n";
    getchar();
}