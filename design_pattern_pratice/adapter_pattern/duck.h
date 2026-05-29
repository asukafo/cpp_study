#ifndef DUCK_H
#define DUCK_H

#include <iostream>

// Target — the interface clients expect
class Duck
{
public:
    virtual ~Duck() = default;
    virtual void quack() = 0;
    virtual void fly() = 0;
};

// Concrete Target
class MallardDuck : public Duck
{
public:
    void quack() override { std::cout << "Quack!" << std::endl; }
    void fly() override { std::cout << "Duck flying 5 meters..." << std::endl; }
};

#endif // DUCK_H
