#ifndef TEA_H
#define TEA_H

#include <iostream>

#include "caffeine_beverage.h"

class Tea : public CaffeineBeverage
{
protected:
    void brew() override
    {
        std::cout << "Steeping the tea bag" << std::endl;
    }

    void addCondiments() override
    {
        std::cout << "Adding lemon" << std::endl;
    }
};

#endif // TEA_H
