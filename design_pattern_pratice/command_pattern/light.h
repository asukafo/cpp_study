#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <string>

// Receiver
class Light
{
public:
    explicit Light(const std::string &location = "Living Room")
        : location_(location), is_on_(false) {}

    void on()
    {
        is_on_ = true;
        std::cout << location_ << " light is ON" << std::endl;
    }

    void off()
    {
        is_on_ = false;
        std::cout << location_ << " light is OFF" << std::endl;
    }

    bool isOn() const { return is_on_; }
    const std::string &location() const { return location_; }

private:
    std::string location_;
    bool is_on_;
};

#endif // LIGHT_H
