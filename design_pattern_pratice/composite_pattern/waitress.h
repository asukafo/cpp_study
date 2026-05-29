#ifndef WAITRESS_H
#define WAITRESS_H

#include "menu_component.h"

// Client — treats any MenuComponent uniformly
class Waitress
{
public:
    explicit Waitress(MenuComponent *all_menus) : all_menus_(all_menus) {}

    void printMenu()
    {
        // Same call whether all_menus_ is a single item or a tree of menus
        all_menus_->print();
    }

private:
    MenuComponent *all_menus_;
};

#endif // WAITRESS_H
