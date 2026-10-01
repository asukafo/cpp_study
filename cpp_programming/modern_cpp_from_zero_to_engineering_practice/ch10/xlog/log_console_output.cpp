#include "log_console_output.h"
#include <iostream>
void LogConsoleOuput::Ouput(
    const std::string& log)
{
    std::cout << log << std::endl;
}