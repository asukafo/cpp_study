#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

// Interface — Iterator
class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
};

// Interface — Menu (the aggregate)
class Menu
{
public:
    virtual ~Menu() = default;
    virtual Iterator *createIterator() = 0;
};

#endif // ITERATOR_H
