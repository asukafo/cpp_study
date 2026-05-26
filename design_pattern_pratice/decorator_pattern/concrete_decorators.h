#ifndef CONCRETE_DECORATORS_H
#define CONCRETE_DECORATORS_H

#include <string>

#include "condiment_decorator.h"

// Concrete Decorator
class Mocha : public CondimentDecorator
{
public:
    explicit Mocha(Beverage *beverage)
        : CondimentDecorator(beverage) {}

    std::string getDescription() const override
    {
        return beverage_->getDescription() + ", Mocha";
    }

    double cost() const override
    {
        return beverage_->cost() + 0.20;
    }
};

// Concrete Decorator
class Whip : public CondimentDecorator
{
public:
    explicit Whip(Beverage *beverage)
        : CondimentDecorator(beverage) {}

    std::string getDescription() const override
    {
        return beverage_->getDescription() + ", Whip";
    }

    double cost() const override
    {
        return beverage_->cost() + 0.10;
    }
};

#endif // CONCRETE_DECORATORS_H
