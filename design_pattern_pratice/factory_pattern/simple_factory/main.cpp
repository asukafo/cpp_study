#include <iostream>

#include "simple_pizza_factory.h"

int main()
{
    std::cout << "The Simple Factory is not a formal GoF design pattern, but it is\n"
              << "a commonly used programming idiom. It encapsulates object creation\n"
              << "so that the client does not depend on concrete classes directly.\n"
              << std::endl;

    std::cout << "=== Simple Factory: Pizza Store ===" << std::endl;

    SimplePizzaFactory factory;

    Pizza *pizza1 = factory.createPizza("cheese");
    if (pizza1)
    {
        std::cout << "\n--- Order 1: " << pizza1->getName() << " ---" << std::endl;
        pizza1->prepare();
        pizza1->bake();
        pizza1->cut();
        pizza1->box();
        delete pizza1;
    }

    Pizza *pizza2 = factory.createPizza("pepperoni");
    if (pizza2)
    {
        std::cout << "\n--- Order 2: " << pizza2->getName() << " ---" << std::endl;
        pizza2->prepare();
        pizza2->bake();
        pizza2->cut();
        pizza2->box();
        delete pizza2;
    }

    return 0;
}
