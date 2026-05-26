#ifndef CONDIMENT_DECORATOR_H
#define CONDIMENT_DECORATOR_H

#include "beverage.h"

// Abstract Decorator
class CondimentDecorator : public Beverage
{
public:
    explicit CondimentDecorator(Beverage *beverage)
        : beverage_(beverage) {}

    ~CondimentDecorator() override
    {
        delete beverage_;
    }

protected:
    Beverage *beverage_;
};

#endif // CONDIMENT_DECORATOR_H
