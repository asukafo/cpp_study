#ifndef _LOG_FILE_OUTPUT_H_
#define _LOG_FILE_OUTPUT_H_

#include "log_output.h"
#include <fstream>
class LogFileOutput:public LogOutput
{
public:
    bool Open(const std::string& file);

    void Ouput(const std::string& log) override;
private:
    std::ofstream ofs_;
};

#endif //_LOG_FILE_OUTPUT_H_