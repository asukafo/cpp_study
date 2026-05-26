#ifndef CONCRETE_PIZZA_STORES_H
#define CONCRETE_PIZZA_STORES_H

#include "pizza_store.h"
#include "ny_style_pizzas.h"
#include "chicago_style_pizzas.h"

// Concrete Creator — creates NY-style pizzas
class NYPizzaStore : public PizzaStore
{
public:
    Pizza *createPizza(const std::string &type) override
    {
        if (type == "cheese")
            return new NYStyleCheesePizza();
        else if (type == "pepperoni")
            return new NYStylePepperoniPizza();
        return nullptr;
    }
};

// Concrete Creator — creates Chicago-style pizzas
class ChicagoPizzaStore : public PizzaStore
{
public:
    Pizza *createPizza(const std::string &type) override
    {
        if (type == "cheese")
            return new ChicagoStyleCheesePizza();
        else if (type == "pepperoni")
            return new ChicagoStylePepperoniPizza();
        return nullptr;
    }
};

#endif // CONCRETE_PIZZA_STORES_H
