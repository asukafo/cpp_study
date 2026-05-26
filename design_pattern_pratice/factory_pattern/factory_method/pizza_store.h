#ifndef PIZZA_STORE_H
#define PIZZA_STORE_H

#include <memory>

#include "pizza.h"

// Abstract Creator — declares the factory method
class PizzaStore
{
public:
    virtual ~PizzaStore() = default;

    Pizza *orderPizza(const std::string &type)
    {
        Pizza *pizza = createPizza(type);
        if (pizza)
        {
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        return pizza;
    }

    // Factory Method — subclasses decide which concrete product to create
    virtual Pizza *createPizza(const std::string &type) = 0;
};

#endif // PIZZA_STORE_H
