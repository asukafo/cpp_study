#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <string>

#include "caffeine_beverage.h"

class Coffee : public CaffeineBeverage
{
public:
    explicit Coffee(bool wants_condiments = true)
        : wants_condiments_(wants_condiments) {}

protected:
    void brew() override
    {
        std::cout << "Dripping coffee through filter" << std::endl;
    }

    void addCondiments() override
    {
        std::cout << "Adding sugar and milk" << std::endl;
    }

    bool customerWantsCondiments() override
    {
        return wants_condiments_;
    }

private:
    bool wants_condiments_;
};

#endif // COFFEE_H
