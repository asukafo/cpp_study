#ifndef _XEXEC_H_
#define _XEXEC_H_

#include "xlog.h"
#include <string>
#include <queue>
#include <future>
#include <mutex>
class XExec
{
public:
    bool Start(const char* cmd);

    bool Runing() { return runing_; }

    bool GetOuput(std::string &out);
    bool Wait() { return fut_.get(); }
private:
    bool runing_ = false;

    std::queue<std::string> outs_;

    std::future<bool> fut_;

    std::mutex mux_;

};

#endif //_XEXEC_H_