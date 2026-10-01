#include "fftask.h"
#include <iostream>
#include <string>
#include "xexec.h"
#define DEFAULTPASS "0123456789ABCDEF0123456789ABCDEF"
static int TimeToSec(const std::string& s)
{
    if (s.size() < 8)return 0;
    int h = 0;
    int m = 0;
    int sec = 0;
    try
    {
        // 00:02:31
         h = std::stoi(s.substr(0, 2));
         m = std::stoi(s.substr(3, 2));
         sec = std::stoi(s.substr(6, 2));
    }
    catch (const std::exception&)
    {
    }
    return h * 3600 + m * 60 + sec;
}
bool FFTask::Start(const Data& para)
{
    std::cout << "FFTask Start" << std::endl;
    //ffmpeg -y -i test.mp4 out.mp4
    // -nostdin: keep ffmpeg/ffplay from reading stdin (stealing input from UserInput)
    std::string cmd = "ffmpeg -y -nostdin ";
    if (para.type == "play")
    {
        cmd = "ffplay -nostdin ";
    }

    if (para.begin_sec > 0)
    {
        cmd += " -ss " + std::to_string(para.begin_sec);
    }
    if (para.end_sec > 0)
    {
        int t = para.end_sec - para.begin_sec;
        if(t>0)
            cmd += " -t " + std::to_string(t);
    }

    ///ffmpeg -decryption_key 1234566789ABCDEF0123456789ABCDEF -i out.mp4 outde.mp4
    if (!para.is_enc)
    {
        if (!para.password.empty())
        {
            std::string pass = DEFAULTPASS;
            for (int i = 0;
                i < para.password.size() && i < pass.size(); i++)
            {
                pass[i] = para.password[i];
            }
            cmd += "  -decryption_key ";
            cmd += pass;
        }
    }

    cmd += " -i " + para.src;

    //ffmpeg -y -i test.mp4 -encryption_key  0123456789ABCDEF0123456789ABCDEF -encryption_scheme cenc-aes-ctr -encryption_kid 0123456789ABCDEF0123456789ABCDEF  en.mp4
    

    if (!para.password.empty() && para.is_enc)
    {
        std::string pass = DEFAULTPASS;
        cmd += " -encryption_scheme cenc-aes-ctr -encryption_kid 0123456789ABCDEF0123456789ABCDEF ";
        cmd += " -encryption_key ";
        for (int i = 0;
            i < para.password.size() && i < pass.size(); i++)
        {
            pass[i] = para.password[i];
        }
        cmd += pass;
    }


    if(!para.des.empty())
        cmd += " "+ para.des;

    // ffmpeg writes progress to stderr; redirect it to stdout so it can be captured
    cmd += " 2>&1";

    std::cout << "cmd:" << cmd << std::endl;

    exec_.Start(cmd.c_str(), [this](const std::string &s) {
        //cout << s << endl;
        //Duration: 00:02:31.17, start: 0.000000, bitrate: 575 kb/s
        if (total_sec_ <= 0)
        {
            auto pos = s.find("Duration: ");
            if (pos != std::string::npos)
            {
                std::string tmp = s.substr(pos + 10, 8);
                // 00:02:31
                //cout << tmp << endl;
                total_sec_ = TimeToSec(tmp);
                std::cout << "total sec = " << TotalSec() <<" s" << std::endl;
                return;
            }
         }
//frame=  604 fps=294 q=29.0 size=    1280KiB time=00:00:20.06 bitrate= 522.6kbits/s speed=9.77x
        {
            auto pos = s.find("time=");
            if (pos != std::string::npos)
            {
                    std::string tmp = s.substr(pos + 5, 8);
                    int p = TimeToSec(tmp);
                    if (total_sec_ > 0)
                        progress_ = p * 100 / total_sec_;
                    return;
            }
        }
        
        });

    return true;
}