#ifndef DINER_MENU_H
#define DINER_MENU_H

#include <array>

#include "iterator.h"
#include "menu_item.h"

// Aggregate backed by fixed-size array
class DinerMenu : public Menu
{
public:
    static constexpr int MAX_ITEMS = 4;
    using MenuArray = std::array<MenuItem, MAX_ITEMS>;

    DinerMenu()
        : items_{
              MenuItem("Vegetarian BLT", "Fake bacon with lettuce and tomato on whole wheat", true, 2.99),
              MenuItem("BLT", "Bacon with lettuce and tomato on whole wheat", false, 2.99),
              MenuItem("Soup of the day", "Soup of the day with a side of potato salad", false, 3.29),
              MenuItem("Hotdog", "A hot dog with sauerkraut, relish, onions, topped with cheese", false, 3.05)}
    {
    }

    Iterator *createIterator() override;

    MenuArray &getItems() { return items_; }

private:
    MenuArray items_;
};

// Concrete Iterator for std::array
class DinerMenuIterator : public Iterator
{
public:
    using MenuArray = DinerMenu::MenuArray;

    explicit DinerMenuIterator(MenuArray &items)
        : items_(items), pos_(0) {}

    bool hasNext() override
    {
        return pos_ < items_.size();
    }

    std::string next() override
    {
        return items_[pos_++].toString();
    }

private:
    MenuArray &items_;
    size_t pos_;
};

inline Iterator *DinerMenu::createIterator()
{
    return new DinerMenuIterator(items_);
}

#endif // DINER_MENU_H
