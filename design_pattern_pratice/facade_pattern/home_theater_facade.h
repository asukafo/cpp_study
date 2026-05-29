#ifndef HOME_THEATER_FACADE_H
#define HOME_THEATER_FACADE_H

#include <string>

#include "home_theater.h"

// Facade — simplifies the subsystem into two high-level operations
class HomeTheaterFacade
{
public:
    HomeTheaterFacade(Amplifier *amp,
                      DvdPlayer *dvd,
                      Projector *projector,
                      Screen *screen,
                      TheaterLights *lights,
                      PopcornPopper *popper)
        : amp_(amp), dvd_(dvd), projector_(projector),
          screen_(screen), lights_(lights), popper_(popper) {}

    void watchMovie(const std::string &movie)
    {
        std::cout << "\n--- Get ready to watch a movie! ---\n";
        popper_->on();
        lights_->dim(10);
        screen_->down();
        projector_->on();
        projector_->wideScreenMode();
        amp_->on();
        amp_->setVolume(11);
        dvd_->on();
        dvd_->play(movie);
    }

    void endMovie()
    {
        std::cout << "\n--- Shutting down home theater... ---\n";
        popper_->off();
        lights_->on();
        dvd_->stop();
        dvd_->off();
        amp_->off();
        projector_->off();
        screen_->up();
    }

private:
    Amplifier *amp_;
    DvdPlayer *dvd_;
    Projector *projector_;
    Screen *screen_;
    TheaterLights *lights_;
    PopcornPopper *popper_;
};

#endif // HOME_THEATER_FACADE_H
