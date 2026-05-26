#ifndef SIMPLE_PIZZA_FACTORY_H
#define SIMPLE_PIZZA_FACTORY_H

#include <string>

#include "concrete_pizzas.h"

// Simple Factory — not a GoF pattern, but a common programming idiom
class SimplePizzaFactory
{
public:
    Pizza *createPizza(const std::string &type)
    {
        if (type == "cheese")
            return new CheesePizza();
        else if (type == "pepperoni")
            return new PepperoniPizza();
        return nullptr;
    }
};

#endif // SIMPLE_PIZZA_FACTORY_H
