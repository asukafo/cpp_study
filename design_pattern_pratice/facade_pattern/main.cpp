#include <iostream>

#include "home_theater.h"
#include "home_theater_facade.h"

int main()
{
    std::cout << "The Facade Pattern provides a unified interface to\n"
              << "a set of interfaces in a subsystem. Facade defines\n"
              << "a higher-level interface that makes the subsystem\n"
              << "easier to use.\n"
              << std::endl;

    std::cout << "=== Facade Pattern: Home Theater ===" << std::endl;

    Amplifier amp;
    DvdPlayer dvd;
    Projector projector;
    Screen screen;
    TheaterLights lights;
    PopcornPopper popper;

    HomeTheaterFacade theater(&amp, &dvd, &projector, &screen, &lights, &popper);

    theater.watchMovie("Inception");
    theater.endMovie();

    return 0;
}
