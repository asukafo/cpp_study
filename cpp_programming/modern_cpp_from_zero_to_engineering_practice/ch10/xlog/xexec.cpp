#include "xexec.h"
#include <cstdio>
#include <iostream>
#include <string>

bool XExec::Start(const char* cmd,
    std::function<void(const std::string&)> cb)
{
    cb_ = cb;
    std::cout << "Start Cmd:" << cmd << std::endl;
    auto fp = popen(cmd, "r");
    if (!fp)return false;
    runing_ = true;

    fut_ = std::async([fp,this] {
        std::string tmp;
        int c = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            // \r returns to start of current line
            // \n goes to start of next line
            if (c == '\n' || c == '\r')
            {
                //cout << tmp << endl;
                if (tmp.empty())continue;
                {
                    std::lock_guard<std::mutex> lock(mux_);
                    outs_.push(tmp);
                }
                if (cb_)
                    cb_(tmp);

                tmp = "";
                continue;
            }
            tmp += c;
        }
        pclose(fp);
        runing_ = false;
        return true;
        });

    return true;
}

bool XExec::GetOuput(std::string& out)
{
    std::lock_guard<std::mutex> lock(mux_);
    if (outs_.empty())return false;
    out = std::move(outs_.front());
    outs_.pop();
    return true;
}