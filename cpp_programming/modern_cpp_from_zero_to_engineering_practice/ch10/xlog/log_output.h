#ifndef _LOG_OUTPUT_H_
#define _LOG_OUTPUT_H_

#include <string>

class LogOutput
{
public:
    virtual void Ouput(const std::string& log) = 0;
};

#endif // _LOG_OUTPUT_H_