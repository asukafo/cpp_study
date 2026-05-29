#ifndef MENU_COMPONENT_H
#define MENU_COMPONENT_H

#include <iostream>
#include <string>

// Component — common interface for both leaves and composites
class MenuComponent
{
public:
    virtual ~MenuComponent() = default;

    virtual void add(MenuComponent * /*component*/) {}
    virtual void remove(MenuComponent * /*component*/) {}
    virtual MenuComponent *getChild(int /*i*/) { return nullptr; }

    virtual std::string getName() const { return ""; }
    virtual std::string getDescription() const { return ""; }
    virtual double getPrice() const { return 0.0; }
    virtual bool isVegetarian() const { return false; }

    // Common operation — works uniformly on leaves and composites
    virtual void print() const = 0;
};

#endif // MENU_COMPONENT_H
