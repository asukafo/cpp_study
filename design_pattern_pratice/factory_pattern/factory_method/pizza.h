#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>

// Interface/Base class — Product
class Pizza
{
public:
    virtual ~Pizza() = default;

    virtual void prepare()
    {
        std::cout << "Preparing " << name_ << "\n"
                  << "  dough: " << dough_ << "\n"
                  << "  sauce: " << sauce_ << "\n"
                  << "  toppings: " << toppings_ << std::endl;
    }

    virtual void bake()  { std::cout << "Bake for 25 minutes at 350" << std::endl; }
    virtual void cut()   { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
    virtual void box()   { std::cout << "Place pizza in official PizzaStore box" << std::endl; }

    std::string getName() const { return name_; }

protected:
    std::string name_;
    std::string dough_;
    std::string sauce_;
    std::string toppings_;
};

#endif // PIZZA_H
