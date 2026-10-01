#ifndef _LOG_FORMAT_H_
#define _LOG_FORMAT_H_

#include <string>

class LogFormat
{
public:
    virtual std::string Format(
        const std::string& level,
        const std::string& log,
        const std::string& file,
        int line
    ) = 0;
};

#endif // _LOG_OUTPUT_H_