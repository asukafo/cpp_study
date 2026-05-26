#ifndef CHICAGO_STYLE_PIZZAS_H
#define CHICAGO_STYLE_PIZZAS_H

#include "pizza.h"

// Concrete Product — Chicago style
class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza()
    {
        name_     = "Chicago Style Deep Dish Cheese Pizza";
        dough_    = "Extra Thick Crust Dough";
        sauce_    = "Plum Tomato Sauce";
        toppings_ = "Shredded Mozzarella Cheese";
    }

    void cut() override
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

// Concrete Product — Chicago style
class ChicagoStylePepperoniPizza : public Pizza
{
public:
    ChicagoStylePepperoniPizza()
    {
        name_     = "Chicago Style Deep Dish Pepperoni Pizza";
        dough_    = "Extra Thick Crust Dough";
        sauce_    = "Plum Tomato Sauce";
        toppings_ = "Pepperoni, Shredded Mozzarella Cheese";
    }

    void cut() override
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

#endif // CHICAGO_STYLE_PIZZAS_H
