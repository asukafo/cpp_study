#include "log_fac.h"
#include "log_console_output.h"

#include "log_file_output.h"
#include "xlog_format.h"
#include "xconfig.h"
#define LOGFILE "log.txt"
#include <iostream>
void LogFac::Init(
    const std::string& con_file)
{
    
    logger_.SetFormat(
        std::make_unique<XLogFormat>());

    XConfig conf;
    bool re = conf.Read(con_file);
    std::string log_type = "console";
    std::string log_file = LOGFILE;
    std::string log_level = "debug";
    if(re)
    {
        log_type = conf.Get("log_type");
        log_file = conf.Get("log_file");
        log_level = conf.Get("log_level");
    }

    if (log_level == "info")
    {
        logger_.SetLevel(XLog::INFO);
    }
    else if (log_level == "error")
    {
        logger_.SetLevel(XLog::ERROR);

    }
    else if (log_level == "fatal")
    {
        logger_.SetLevel(XLog::ERROR);
    }

    if (log_type == "file")
    {
        if (log_file.empty())
        {
            log_file = LOGFILE;
        }
        auto fout = 
            std::make_unique<LogFileOutput>();//new LogFileOutput();
        if (!fout->Open(log_file))
        {
            std::cerr << "open file failed "
                << log_file << std::endl;
        }
        logger_.SetOutput(std::move(fout));
    }
    else
    {
        logger_.SetOutput(
            std::make_unique<LogConsoleOuput>()
            );
    }
}