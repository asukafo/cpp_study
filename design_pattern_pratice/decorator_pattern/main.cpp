#include <iostream>

#include "concrete_beverages.h"
#include "concrete_decorators.h"

int main()
{
    std::cout << "The Decorator Pattern attaches additional responsibilities\n"
              << "to an object dynamically. Decorators provide a flexible\n"
              << "alternative to subclassing for extending functionality.\n"
              << std::endl;

    std::cout << "=== Decorator Pattern: Starbuzz Coffee ===" << std::endl;

    Beverage *beverage1 = new Espresso();
    std::cout << "\n[1] " << beverage1->getDescription()
              << "  $" << beverage1->cost() << std::endl;
    delete beverage1;

    Beverage *beverage2 = new HouseBlend();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << "[2] " << beverage2->getDescription()
              << "  $" << beverage2->cost() << std::endl;
    delete beverage2;

    Beverage *beverage3 = new Espresso();
    beverage3 = new Mocha(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << "[3] " << beverage3->getDescription()
              << "  $" << beverage3->cost() << std::endl;
    delete beverage3;

    return 0;
}
