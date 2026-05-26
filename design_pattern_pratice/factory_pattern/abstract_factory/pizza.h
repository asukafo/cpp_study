#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>

#include "pizza_ingredient_factory.h"

// Base class — uses ingredient factory to assemble itself
class Pizza
{
public:
    virtual ~Pizza()
    {
        delete dough_;
        delete sauce_;
        delete cheese_;
    }

    virtual void prepare() = 0;

    virtual void bake()  { std::cout << "Bake for 25 minutes at 350" << std::endl; }
    virtual void cut()   { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
    virtual void box()   { std::cout << "Place pizza in official PizzaStore box" << std::endl; }

    std::string getName() const { return name_; }
    void setName(const std::string &name) { name_ = name; }

protected:
    std::string name_;
    Dough  *dough_ = nullptr;
    Sauce  *sauce_ = nullptr;
    Cheese *cheese_ = nullptr;
};

// Concrete Product — uses the ingredient factory for its region
class CheesePizza : public Pizza
{
public:
    explicit CheesePizza(PizzaIngredientFactory *factory)
        : ingredientFactory_(factory) {}

    void prepare() override
    {
        std::cout << "Preparing " << name_ << std::endl;
        dough_  = ingredientFactory_->createDough();
        sauce_  = ingredientFactory_->createSauce();
        cheese_ = ingredientFactory_->createCheese();
        dough_->describe();
        sauce_->describe();
        cheese_->describe();
    }

private:
    PizzaIngredientFactory *ingredientFactory_;
};

// Concrete Product — uses the ingredient factory for its region
class PepperoniPizza : public Pizza
{
public:
    explicit PepperoniPizza(PizzaIngredientFactory *factory)
        : ingredientFactory_(factory) {}

    void prepare() override
    {
        std::cout << "Preparing " << name_ << std::endl;
        dough_  = ingredientFactory_->createDough();
        sauce_  = ingredientFactory_->createSauce();
        cheese_ = ingredientFactory_->createCheese();
        dough_->describe();
        sauce_->describe();
        cheese_->describe();
    }

private:
    PizzaIngredientFactory *ingredientFactory_;
};

#endif // PIZZA_H
