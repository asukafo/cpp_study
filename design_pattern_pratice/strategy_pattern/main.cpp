#include <iostream>
#include <memory>
#include <vector>

#include "iweapon.h"
#include "character.h"

int main()
{
    std::cout << "Strategy Pattern: defines a family of algorithms, encapsulates each one,\n"
              << "and makes them interchangeable. Strategy lets the algorithm vary\n"
              << "independently from clients that use it.\n"
              << std::endl;
    std::cout << "=== Strategy Pattern: Character Classes ===" << std::endl;

    // Each character type is its own class
    Knight knight(std::make_unique<Sword>());
    Archer archer(std::make_unique<Bow>());
    Barbarian barbarian(std::make_unique<Axe>());

    knight.fight();
    archer.fight();
    barbarian.fight();

    std::cout << "\n--- Swap weapons at runtime ---" << std::endl;

    knight.setWeapon(std::make_unique<Axe>());
    knight.fight();

    archer.setWeapon(std::make_unique<Sword>());
    archer.fight();

    // Polymorphism: treat all characters uniformly
    std::cout << "\n--- Polymorphic fight ---" << std::endl;
    std::vector<std::unique_ptr<Character>> team;
    team.push_back(std::make_unique<Knight>(std::make_unique<Sword>()));
    team.push_back(std::make_unique<Archer>(std::make_unique<Bow>()));
    team.push_back(std::make_unique<Barbarian>(std::make_unique<Axe>()));

    for (const auto& m : team) 
    {
        m->fight();
    }

    return 0;
}