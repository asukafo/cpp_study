#include <iostream>

#include "logger.h"

void doWork()
{
    Logger &log = Logger::getInstance();
    log.log("doWork() called");
}

int main()
{
    std::cout << "The Singleton Pattern ensures a class has only one instance,\n"
              << "and provides a global point of access to it.\n"
              << std::endl;

    std::cout << "=== Singleton Pattern: Logger ===" << std::endl;

    std::cout << "\n[1] Getting instance..." << std::endl;
    Logger &log1 = Logger::getInstance();
    log1.log("First log message");
    log1.log("Second log message");

    std::cout << "\n[2] Getting instance again (same instance expected)..." << std::endl;
    Logger &log2 = Logger::getInstance();
    log2.log("Third log message");

    std::cout << "\n[3] Calling doWork() which also gets the instance..." << std::endl;
    doWork();

    std::cout << "\n--- Result ---" << std::endl;
    std::cout << "Total log count: " << log1.getCount() << std::endl;
    std::cout << "&log1 == &log2: " << (&log1 == &log2 ? "true (same instance)" : "false")
              << std::endl;

    return 0;
}
