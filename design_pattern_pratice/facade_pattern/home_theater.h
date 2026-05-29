#ifndef HOME_THEATER_H
#define HOME_THEATER_H

#include <iostream>
#include <string>

// Subsystem classes — complex, low-level device APIs

class Amplifier
{
public:
    void on() { std::cout << "Amplifier: ON" << std::endl; }
    void off() { std::cout << "Amplifier: OFF" << std::endl; }
    void setVolume(int level)
    {
        std::cout << "Amplifier: volume set to " << level << std::endl;
    }
};

class DvdPlayer
{
public:
    void on() { std::cout << "DVD Player: ON" << std::endl; }
    void off() { std::cout << "DVD Player: OFF" << std::endl; }
    void play(const std::string &movie)
    {
        std::cout << "DVD Player: playing \"" << movie << "\"" << std::endl;
    }
    void stop() { std::cout << "DVD Player: stopped" << std::endl; }
};

class Projector
{
public:
    void on() { std::cout << "Projector: ON" << std::endl; }
    void off() { std::cout << "Projector: OFF" << std::endl; }
    void wideScreenMode()
    {
        std::cout << "Projector: widescreen mode (16:9)" << std::endl;
    }
};

class Screen
{
public:
    void down() { std::cout << "Screen: rolling down" << std::endl; }
    void up() { std::cout << "Screen: rolling up" << std::endl; }
};

class TheaterLights
{
public:
    void dim(int level)
    {
        std::cout << "Lights: dimming to " << level << "%" << std::endl;
    }
    void on() { std::cout << "Lights: ON" << std::endl; }
};

class PopcornPopper
{
public:
    void on() { std::cout << "Popcorn Popper: ON, popping!" << std::endl; }
    void off() { std::cout << "Popcorn Popper: OFF" << std::endl; }
};

#endif // HOME_THEATER_H
