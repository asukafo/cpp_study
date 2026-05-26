#ifndef PIZZA_INGREDIENT_FACTORY_H
#define PIZZA_INGREDIENT_FACTORY_H

#include "ingredients.h"

// Abstract Factory — creates a family of related products
class PizzaIngredientFactory
{
public:
    virtual ~PizzaIngredientFactory() = default;
    virtual Dough  *createDough()  = 0;
    virtual Sauce  *createSauce()  = 0;
    virtual Cheese *createCheese() = 0;
};

#endif // PIZZA_INGREDIENT_FACTORY_H
