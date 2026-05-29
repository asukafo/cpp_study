#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <iomanip>
#include <string>

#include "menu_component.h"

// Leaf — a single menu item with no children
class MenuItem : public MenuComponent
{
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price)
        : name_(std::move(name)),
          description_(std::move(description)),
          vegetarian_(vegetarian),
          price_(price) {}

    std::string getName() const override { return name_; }
    std::string getDescription() const override { return description_; }
    double getPrice() const override { return price_; }
    bool isVegetarian() const override { return vegetarian_; }

    void print() const override
    {
        std::cout << "  " << name_;
        if (vegetarian_)
            std::cout << " (v)";
        std::cout << std::fixed << std::setprecision(2)
                  << "  $" << price_ << "  -- " << description_
                  << std::endl;
    }

private:
    std::string name_;
    std::string description_;
    bool vegetarian_;
    double price_;
};

#endif // MENU_ITEM_H
