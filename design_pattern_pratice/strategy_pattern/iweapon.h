#ifndef IWEAPON_H
#define IWEAPON_H

#include <iostream>
#include <string>

// Abstract Interface Class
class IWeapon
{
public:
    virtual ~IWeapon() = default;
    virtual void useWeapon() const = 0;
};

// Concrete Class
class Sword : public IWeapon
{
public:
    void useWeapon() const override
    {
        std::cout << "Swings a sword! Slash!" << std::endl;
    }
};


class Bow : public IWeapon
{
public:
    void useWeapon() const override
    {
        std::cout << "Shoots an arrow! Twang! " << std::endl;
    }
};

class Axe : public IWeapon
{
public:
    void useWeapon() const override
    {
        std::cout << "Swings a heavy axe! Crush!" << std::endl;
    }
};


#endif // IWEAPON_H
