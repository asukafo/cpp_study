#ifndef NY_STYLE_PIZZAS_H
#define NY_STYLE_PIZZAS_H

#include "pizza.h"

// Concrete Product — New York style
class NYStyleCheesePizza : public Pizza
{
public:
    NYStyleCheesePizza()
    {
        name_     = "NY Style Sauce and Cheese Pizza";
        dough_    = "Thin Crust Dough";
        sauce_    = "Marinara Sauce";
        toppings_ = "Grated Reggiano Cheese";
    }
};

// Concrete Product — New York style
class NYStylePepperoniPizza : public Pizza
{
public:
    NYStylePepperoniPizza()
    {
        name_     = "NY Style Pepperoni Pizza";
        dough_    = "Thin Crust Dough";
        sauce_    = "Marinara Sauce";
        toppings_ = "Pepperoni, Grated Reggiano Cheese";
    }
};

#endif // NY_STYLE_PIZZAS_H
