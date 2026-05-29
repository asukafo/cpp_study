#ifndef PANCAKE_HOUSE_MENU_H
#define PANCAKE_HOUSE_MENU_H

#include <vector>

#include "iterator.h"
#include "menu_item.h"

// Aggregate backed by std::vector
class PancakeHouseMenu : public Menu
{
public:
    PancakeHouseMenu()
    {
        items_.emplace_back("K&B Pancake Breakfast", "Pancakes with scrambled eggs and toast", false, 2.99);
        items_.emplace_back("Regular Pancake Breakfast", "Pancakes with fried eggs and sausage", false, 2.99);
        items_.emplace_back("Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49);
        items_.emplace_back("Waffles", "Waffles with your choice of blueberries or strawberries", true, 3.59);
    }

    Iterator *createIterator() override;

    std::vector<MenuItem> &getItems() { return items_; }

private:
    std::vector<MenuItem> items_;
};

// Concrete Iterator for std::vector
class PancakeHouseIterator : public Iterator
{
public:
    explicit PancakeHouseIterator(std::vector<MenuItem> &items)
        : items_(items), pos_(0) {}

    bool hasNext() override { return pos_ < items_.size(); }

    std::string next() override { return items_[pos_++].toString(); }

private:
    std::vector<MenuItem> &items_;
    size_t pos_;
};

inline Iterator *PancakeHouseMenu::createIterator()
{
    return new PancakeHouseIterator(items_);
}

#endif // PANCAKE_HOUSE_MENU_H
