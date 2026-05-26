#ifndef CONCRETE_INGREDIENT_FACTORIES_H
#define CONCRETE_INGREDIENT_FACTORIES_H

#include "pizza_ingredient_factory.h"

// Concrete Factory — NY ingredient family
class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    Dough  *createDough()  override { return new ThinCrustDough(); }
    Sauce  *createSauce()  override { return new MarinaraSauce(); }
    Cheese *createCheese() override { return new ReggianoCheese(); }
};

// Concrete Factory — Chicago ingredient family
class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    Dough  *createDough()  override { return new ThickCrustDough(); }
    Sauce  *createSauce()  override { return new PlumTomatoSauce(); }
    Cheese *createCheese() override { return new MozzarellaCheese(); }
};

#endif // CONCRETE_INGREDIENT_FACTORIES_H
