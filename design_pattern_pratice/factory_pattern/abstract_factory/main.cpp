#include <iostream>

#include "concrete_ingredient_factories.h"
#include "pizza.h"

int main()
{
    std::cout << "The Abstract Factory Pattern provides an interface for creating\n"
              << "families of related or dependent objects without specifying\n"
              << "their concrete classes.\n"
              << std::endl;

    std::cout << "=== Abstract Factory: Pizza Ingredient Factories ===" << std::endl;

    NYPizzaIngredientFactory nyFactory;
    ChicagoPizzaIngredientFactory chicagoFactory;

    std::cout << "\n--- [NY Factory] Cheese Pizza ---" << std::endl;
    CheesePizza nyCheese(&nyFactory);
    nyCheese.setName("New York Style Cheese Pizza");
    nyCheese.prepare();
    nyCheese.bake();
    nyCheese.cut();
    nyCheese.box();

    std::cout << "\n--- [Chicago Factory] Pepperoni Pizza ---" << std::endl;
    PepperoniPizza chicagoPepperoni(&chicagoFactory);
    chicagoPepperoni.setName("Chicago Style Pepperoni Pizza");
    chicagoPepperoni.prepare();
    chicagoPepperoni.bake();
    chicagoPepperoni.cut();
    chicagoPepperoni.box();

    return 0;
}
