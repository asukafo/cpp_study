#include <iostream>

#include "concrete_pizza_stores.h"

int main()
{
    std::cout << "The Factory Method Pattern defines an interface for creating\n"
              << "an object, but lets subclasses decide which class to instantiate.\n"
              << "Factory Method lets a class defer instantiation to subclasses.\n"
              << std::endl;

    std::cout << "=== Factory Method: Regional Pizza Stores ===" << std::endl;

    NYPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;

    std::cout << "\n--- [NY Store] Order cheese pizza ---" << std::endl;
    Pizza *pizza1 = nyStore.orderPizza("cheese");
    delete pizza1;

    std::cout << "\n--- [Chicago Store] Order pepperoni pizza ---" << std::endl;
    Pizza *pizza2 = chicagoStore.orderPizza("pepperoni");
    delete pizza2;

    return 0;
}
