#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <iostream>

// Abstract Product A
class Dough
{
public:
    virtual ~Dough() = default;
    virtual void describe() const = 0;
};

// Abstract Product B
class Sauce
{
public:
    virtual ~Sauce() = default;
    virtual void describe() const = 0;
};

// Abstract Product C
class Cheese
{
public:
    virtual ~Cheese() = default;
    virtual void describe() const = 0;
};

// Concrete Product A1
class ThinCrustDough : public Dough
{
public:
    void describe() const override { std::cout << "  Thin Crust Dough" << std::endl; }
};

// Concrete Product A2
class ThickCrustDough : public Dough
{
public:
    void describe() const override { std::cout << "  Extra Thick Crust Dough" << std::endl; }
};

// Concrete Product B1
class MarinaraSauce : public Sauce
{
public:
    void describe() const override { std::cout << "  Marinara Sauce" << std::endl; }
};

// Concrete Product B2
class PlumTomatoSauce : public Sauce
{
public:
    void describe() const override { std::cout << "  Plum Tomato Sauce" << std::endl; }
};

// Concrete Product C1
class ReggianoCheese : public Cheese
{
public:
    void describe() const override { std::cout << "  Grated Reggiano Cheese" << std::endl; }
};

// Concrete Product C2
class MozzarellaCheese : public Cheese
{
public:
    void describe() const override { std::cout << "  Shredded Mozzarella Cheese" << std::endl; }
};

#endif // INGREDIENTS_H
