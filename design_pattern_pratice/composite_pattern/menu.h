#ifndef MENU_H
#define MENU_H

#include <vector>

#include "menu_component.h"

// Composite — holds children and delegates print() to them
class Menu : public MenuComponent
{
public:
    explicit Menu(std::string name, std::string description)
        : name_(std::move(name)), description_(std::move(description)) {}

    ~Menu()
    {
        for (MenuComponent *c : components_)
            delete c;
    }

    void add(MenuComponent *component) override
    {
        components_.push_back(component);
    }

    void remove(MenuComponent *component) override
    {
        auto it = std::find(components_.begin(), components_.end(), component);
        if (it != components_.end())
            components_.erase(it);
    }

    MenuComponent *getChild(int i) override
    {
        return (i >= 0 && static_cast<size_t>(i) < components_.size())
                   ? components_[i]
                   : nullptr;
    }

    std::string getName() const override { return name_; }
    std::string getDescription() const override { return description_; }

    void print() const override
    {
        std::cout << "\n" << name_;
        std::cout << "  -- " << description_ << std::endl;
        std::cout << "---------------------------------\n";
        for (MenuComponent *c : components_)
            c->print();
    }

private:
    std::string name_;
    std::string description_;
    std::vector<MenuComponent *> components_;
};

#endif // MENU_H
