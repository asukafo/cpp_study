#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#include "xlog.h"
#include <map>
#include <string>
#include <vector>
#include <functional>
class XLOG_API UserInput
{
public:
    void Start(std::function<void(const std::vector<std::string>&)> init = nullptr);
    void Stop() { is_exit_ = true; }

    UserInput& Reg(std::string key,
        std::function<void(const std::string&)> func)
    {
        key_funcs_[key] = func;
        return *this;
    }
    UserInput& RegTask(std::string key,
        std::function<void()> func)
    {
        task_funcs_[key] = func;
        return *this;
    }

private:
    bool is_exit_{ false };

    std::map<std::string,  //key -s -d  
        std::function<void (const std::string&)>
    > key_funcs_;
    //std::function<void()> init_func_ = [] {};

    std::map<std::string,
       std::function<void()>
    > task_funcs_;
};

#endif //_USER_INPUT_H_