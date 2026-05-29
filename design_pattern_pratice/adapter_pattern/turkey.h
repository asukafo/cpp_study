#ifndef TURKEY_H
#define TURKEY_H

#include <iostream>

// Adaptee — the existing interface that needs adapting
class Turkey
{
public:
    virtual ~Turkey() = default;
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

// Concrete Adaptee
class WildTurkey : public Turkey
{
public:
    void gobble() override { std::cout << "Gobble gobble!" << std::endl; }
    void fly() override { std::cout << "Turkey flying 1 meter..." << std::endl; }
};

#endif // TURKEY_H
