#include <iostream>

#include "diner_menu.h"
#include "pancake_house_menu.h"
#include "waitress.h"

int main()
{
    std::cout << "The Iterator Pattern provides a way to access the\n"
              << "elements of an aggregate object sequentially\n"
              << "without exposing its underlying representation.\n"
              << std::endl;

    std::cout << "=== Iterator Pattern: Restaurant Menus ===" << std::endl;

    PancakeHouseMenu pancake_menu;
    DinerMenu diner_menu;
    Waitress waitress(&pancake_menu, &diner_menu);

    waitress.printMenu();

    return 0;
}
