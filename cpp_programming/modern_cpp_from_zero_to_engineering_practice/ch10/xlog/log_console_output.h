#ifndef _LOG_CONSOLE_OUTPUT_H_
#define _LOG_CONSOLE_OUTPUT_H_

#include "log_output.h"
class LogConsoleOuput :
    public LogOutput
{
public:
    void Ouput(const std::string& log) override;
};

#endif // _LOG_CONSOLE_OUTPUT_H_