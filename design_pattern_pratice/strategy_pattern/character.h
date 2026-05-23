#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <iostream>

#include "iweapon.h"

// Abstract Base Class
class Character
{
public:
    explicit Character(std::unique_ptr<IWeapon> weapon)
        : weapon_(std::move(weapon)) {}
    virtual ~Character() = default;

    void setWeapon(std::unique_ptr<IWeapon> weapon)
    {
        weapon_ = std::move(weapon);
    }

    virtual void fight() const = 0;

protected:
    std::unique_ptr<IWeapon> weapon_;
};


// Concrete character: Knight
class Knight final : public Character
{
public:
    explicit Knight(std::unique_ptr<IWeapon> weapon)
        : Character(std::move(weapon)) {}

    void fight() const override
    {
        std::cout << "Knight ";
        weapon_->useWeapon();
    }
};

// Concrete character: Archer
class Archer final : public Character
{
public:
    explicit Archer(std::unique_ptr<IWeapon> weapon)
        : Character(std::move(weapon)) {}

    void fight() const override
    {
        std::cout << "Archer ";
        weapon_->useWeapon();
    }
};

// Concrete character: Barbarian
class Barbarian final : public Character
{
public: 
    explicit Barbarian(std::unique_ptr<IWeapon> weapon)
        : Character(std::move(weapon)) {}

    void fight() const override 
    {
        std::cout << "Barbarian ";
        weapon_->useWeapon();
    }
};

#endif // CHARACTER_H