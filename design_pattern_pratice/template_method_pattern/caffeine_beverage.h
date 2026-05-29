#ifndef CAFFEINE_BEVERAGE_H
#define CAFFEINE_BEVERAGE_H

#include <iostream>

// Abstract class — defines the template method and primitive operations
class CaffeineBeverage
{
public:
    virtual ~CaffeineBeverage() = default;

    // Template method — the algorithm skeleton (final, not to be overridden)
    void prepareRecipe()
    {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments())
            addCondiments();
    }

protected:
    // Primitive operations — must be implemented by subclasses
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    // Concrete operations — shared by all subclasses
    void boilWater()
    {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup()
    {
        std::cout << "Pouring into cup" << std::endl;
    }

    // Hook — subclasses can optionally override (default: true)
    virtual bool customerWantsCondiments() { return true; }
};

#endif // CAFFEINE_BEVERAGE_H
