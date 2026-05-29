#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>

class MenuItem
{
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price)
        : name_(std::move(name)),
          description_(std::move(description)),
          vegetarian_(vegetarian),
          price_(price) {}

    const std::string &getName() const { return name_; }
    const std::string &getDescription() const { return description_; }
    bool isVegetarian() const { return vegetarian_; }
    double getPrice() const { return price_; }

    std::string toString() const
    {
        return name_ + "  $" + std::to_string(price_).substr(0, 4)
               + "  (" + (vegetarian_ ? "v" : "meat") + ")  " + description_;
    }

private:
    std::string name_;
    std::string description_;
    bool vegetarian_;
    double price_;
};

#endif // MENU_ITEM_H
