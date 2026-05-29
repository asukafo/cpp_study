#ifndef WAITRESS_H
#define WAITRESS_H

#include <iostream>

#include "iterator.h"

// Client — works with any Menu through the Iterator interface
class Waitress
{
public:
    explicit Waitress(Menu *pancake_menu, Menu *diner_menu)
        : pancake_menu_(pancake_menu), diner_menu_(diner_menu) {}

    void printMenu()
    {
        Iterator *pancake_it = pancake_menu_->createIterator();
        Iterator *diner_it = diner_menu_->createIterator();

        std::cout << "\n--- Pancake House Menu (vector-based) ---\n";
        printItems(pancake_it);

        std::cout << "\n--- Diner Menu (array-based) ---\n";
        printItems(diner_it);

        delete pancake_it;
        delete diner_it;
    }

private:
    void printItems(Iterator *it)
    {
        while (it->hasNext())
            std::cout << "  " << it->next() << std::endl;
    }

    Menu *pancake_menu_;
    Menu *diner_menu_;
};

#endif // WAITRESS_H
