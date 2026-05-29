#include <iostream>

#include "menu.h"
#include "menu_item.h"
#include "waitress.h"

int main()
{
    std::cout << "The Composite Pattern allows you to compose objects\n"
              << "into tree structures to represent part-whole hierarchies.\n"
              << "Composite lets clients treat individual objects and\n"
              << "compositions of objects uniformly.\n"
              << std::endl;

    std::cout << "=== Composite Pattern: Restaurant Menus ===" << std::endl;

    auto *breakfast_menu = new Menu("BREAKFAST MENU", "Pancake House");
    auto *dinner_menu = new Menu("DINNER MENU", "Diner");
    auto *dessert_menu = new Menu("DESSERT MENU", "Desserts!");

    auto *all_menus = new Menu("ALL MENUS", "All our menus combined");
    all_menus->add(breakfast_menu);
    all_menus->add(dinner_menu);

    breakfast_menu->add(new MenuItem(
        "K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", false, 2.99));
    breakfast_menu->add(new MenuItem(
        "Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49));

    dinner_menu->add(new MenuItem(
        "Vegetarian BLT", "Fake bacon with lettuce and tomato on whole wheat", true, 2.99));
    dinner_menu->add(new MenuItem(
        "BLT", "Bacon with lettuce and tomato on whole wheat", false, 2.99));
    dinner_menu->add(dessert_menu);

    dessert_menu->add(new MenuItem(
        "Apple Pie", "Apple pie with a flaky crust, topped with vanilla ice cream", true, 1.59));
    dessert_menu->add(new MenuItem(
        "Cheesecake", "Creamy New York cheesecake with a chocolate crust", true, 1.99));

    Waitress waitress(all_menus);

    // One call traverses the entire tree — leaves and composites treated uniformly
    waitress.printMenu();

    delete all_menus; // cascades to all children via Menu destructor

    return 0;
}
