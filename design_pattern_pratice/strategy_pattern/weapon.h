#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <string>

// virtual Class Interface
class Weapon
{
public: 
    virtual ~Weapon() = default;
    virtual void attack() const = 0;
    virtual std::string getName() const = 0;
};

class Sword : public Weapon
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


class Bow : public Weapon
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

class Axe : public Weapon
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


#endif // __WEAPON_H__