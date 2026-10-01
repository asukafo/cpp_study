#ifndef _XLOG_FORMAT_H_
#define _XLOG_FORMAT_H_

#include "log_format.h"
class XLogFormat : public LogFormat
{
public:
    std::string Format(
        const std::string& level,
        const std::string& log,
        const std::string& file,
        int line
    )  override;
};

#endif // _XLOG_FORMAT_H_