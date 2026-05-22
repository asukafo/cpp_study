#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <memory>
#include <iostream>

#include "weapon.h"

// Abstrace Base Class
class Character
{
public:
    explicit Character(std::unique_ptr<Weapon> weapon)
        : weapon_(std::move(weapon)) {}
    virtual ~Character() = default;

    void setWeapon(std::unique_ptr<Weapon> weapon)
    {
        weapon_ = std::move(weapon);
    }

    virtual void fight() const = 0;
    virtual std::string getName() const = 0;

protected:
    std::unique_ptr<Weapon> weapon_;
};


// Concrete character: Knight
class Knight : public Character
{
public:
    explicit Knight(std::unique_ptr<Weapon> weapon)
        : Character(std::move(weapon)) {}

    void fight() const override
    {
        std::cout << "Knight ";
        weapon_->attack();
    }
    
    std::string getName() const override
    {
        return "Knight";
    }
};

// Concrete character: Archer
class Archer : public Character
{
public:
    explicit Archer(std::unique_ptr<Weapon> weapon)
        : Character(std::move(weapon)) {}

    void fight() const override
    {
        std::cout << "Archer ";
        weapon_->attack();
    }

    std::string getName() const override
    {
        return "Archer";
    }
};

// Concrete character: Barbarian
class Barbarian : public Character
{
public: 
    explicit Barbarian(std::unique_ptr<Weapon> weapon)
        : Character(std::move(weapon)) {}

    void fight() const override 
    {
        std::cout << "Barbarian";
        weapon_->attack();
    }

    std::string getName() const override 
    {
        return "Barbarian";
    }
};

#endif // __CHARACTER_H__