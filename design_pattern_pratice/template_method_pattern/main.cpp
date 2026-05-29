#include <iostream>

#include "caffeine_beverage.h"
#include "coffee.h"
#include "tea.h"

int main()
{
    std::cout << "The Template Method Pattern defines the skeleton\n"
              << "of an algorithm in a method, deferring some steps\n"
              << "to subclasses. Template Method lets subclasses\n"
              << "redefine certain steps of an algorithm without\n"
              << "changing the algorithm structure.\n"
              << std::endl;

    std::cout << "=== Template Method Pattern: Caffeine Beverage ===" << std::endl;

    std::cout << "\n--- Making Tea ---" << std::endl;
    Tea tea;
    tea.prepareRecipe();

    std::cout << "\n--- Making Coffee ---" << std::endl;
    Coffee coffee;
    coffee.prepareRecipe();

    std::cout << "\n--- Making Black Coffee (no condiments) ---" << std::endl;
    Coffee black_coffee(false);
    black_coffee.prepareRecipe();

    return 0;
}
