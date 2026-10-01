#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include "log_format.h"
#include "log_output.h"
#include "xlog.h"
#include <memory>

enum class XLog
{
    DEBUG,
    INFO,
    ERROR,
    FATAL
};
//XLog::DEBUG;
class XLOG_API Logger
{
public:
    void Write(
        XLog level,
        const std::string& log,
        const std::string& file,
        int line
    );
    void SetOutput(
        std::unique_ptr<LogOutput>  o)
    {
        output_ = std::move(o);
    }
    /*
    void SetOutput(
        LogOutput *o)
    {
        output_.reset(o);
    }*/
    void SetFormat(
        std::unique_ptr<LogFormat> f)
    {
        formater_ = std::move(f);
    }
    ~Logger() {
        //delete output_; 
        //output_ = nullptr;
        //delete formater_;
        //formater_ = nullptr;
    }
    void SetLevel(XLog level)
    {
        log_level_ = level;
    }
private:
    //LogOutput* output_{nullptr};
    //LogFormat *formater_{ nullptr };
    std::unique_ptr<LogOutput> output_;
    std::unique_ptr<LogFormat> formater_;
    XLog log_level_{ XLog::DEBUG };
};

#endif //_LOGGER_H_