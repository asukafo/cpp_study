#include <iostream>

#include "duck.h"
#include "turkey.h"
#include "turkey_adapter.h"

// Client — works with any object implementing the Duck interface
void testDuck(Duck *duck)
{
    duck->quack();
    duck->fly();
}

int main()
{
    std::cout << "The Adapter Pattern converts the interface of a class\n"
              << "into another interface the clients expect. Adapter lets\n"
              << "classes work together that couldn't otherwise because\n"
              << "of incompatible interfaces.\n"
              << std::endl;

    std::cout << "=== Adapter Pattern: Turkey Adapter ===" << std::endl;

    MallardDuck duck;
    std::cout << "\n--- Real Duck ---\n";
    testDuck(&duck);

    WildTurkey turkey;
    std::cout << "\n--- Real Turkey ---\n";
    turkey.gobble();
    turkey.fly();

    std::cout << "\n--- Turkey adapted as Duck ---\n";
    TurkeyAdapter turkey_duck(&turkey);
    testDuck(&turkey_duck);

    return 0;
}
