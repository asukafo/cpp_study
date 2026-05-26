#ifndef CONCRETE_PIZZAS_H
#define CONCRETE_PIZZAS_H

#include "pizza.h"

// Concrete Product
class CheesePizza : public Pizza
{
public:
    CheesePizza()
    {
        name_     = "Cheese Pizza";
        dough_    = "Regular Crust";
        sauce_    = "Marinara Pizza Sauce";
        toppings_ = "Fresh Mozzarella, Parmesan";
    }
};

// Concrete Product
class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza()
    {
        name_     = "Pepperoni Pizza";
        dough_    = "Regular Crust";
        sauce_    = "Marinara Pizza Sauce";
        toppings_ = "Pepperoni, Fresh Mozzarella, Parmesan";
    }
};

#endif // CONCRETE_PIZZAS_H
