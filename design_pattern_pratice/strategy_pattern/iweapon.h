#ifndef IWEAPON_H
#define IWEAPON_H

#include <iostream>
#include <string>

// Interface class (pure interface: all functions = 0, no member variables)
class IWeapon
{
public:
    virtual ~IWeapon() = default;
    virtual void attack() const = 0;
    [[nodiscard]] virtual std::string getName() const = 0;
};

class Sword final : public IWeapon
{
public:
    void attack() const override
    {
        std::cout << "Swings a sword! Slash!" << std::endl;
    }

    std::string getName() const override
    {
        return "Sword";
    }
};


class Bow final : public IWeapon
{
public:
    void attack() const override
    {
        std::cout << "Shoots an arrow! Twang! " << std::endl;
    }

    std::string getName() const override
    {
        return "Bow";
    }
};

class Axe final : public IWeapon
{
public:
    void attack() const override
    {
        std::cout << "Swings a heavy axe! Crush!" << std::endl;
    }

    std::string getName() const override
    {
        return "Axe";
    }
};


#endif // IWEAPON_H
