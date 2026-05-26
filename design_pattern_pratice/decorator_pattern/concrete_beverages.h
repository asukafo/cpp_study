#ifndef CONCRETE_BEVERAGES_H
#define CONCRETE_BEVERAGES_H

#include "beverage.h"

// Concrete Component
class Espresso : public Beverage
{
public:
    std::string getDescription() const override
    {
        return "Espresso";
    }

    double cost() const override
    {
        return 1.99;
    }
};

// Concrete Component
class HouseBlend : public Beverage
{
public:
    std::string getDescription() const override
    {
        return "House Blend Coffee";
    }

    double cost() const override
    {
        return 0.89;
    }
};

#endif // CONCRETE_BEVERAGES_H
