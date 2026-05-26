#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

// Singleton — ensures only one instance and provides a global point of access
class Logger
{
public:
    // Deleted to prevent copies
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    // Global access point — Meyers' singleton (thread-safe in C++11)
    static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }

    void log(const std::string &msg)
    {
        std::cout << "[LOG] " << msg << std::endl;
        ++count_;
    }

    int getCount() const { return count_; }

private:
    Logger() { std::cout << "Logger created (private ctor)" << std::endl; }
    ~Logger() = default;

    int count_ = 0;
};

#endif // LOGGER_H
