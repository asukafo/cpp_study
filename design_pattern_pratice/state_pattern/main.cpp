#include <ctime>
#include <iostream>

#include "gumball_machine.h"

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "The State Pattern allows an object to alter its\n"
              << "behavior when its internal state changes. The\n"
              << "object will appear to change its class.\n"
              << std::endl;

    std::cout << "=== State Pattern: Gumball Machine ===" << std::endl;

    GumballMachine machine(3);
    std::cout << "\n" << machine << "\n" << std::endl;

    std::cout << "--- Test 1: try to eject with no quarter ---\n";
    machine.ejectQuarter();

    std::cout << "\n--- Test 2: insert, turn crank ---\n";
    machine.insertQuarter();
    machine.turnCrank();

    std::cout << "\n--- Test 3: insert, then eject ---\n";
    machine.insertQuarter();
    machine.ejectQuarter();

    std::cout << "\n--- Test 4: turn crank with no quarter ---\n";
    machine.turnCrank();

    std::cout << "\n--- Test 5: buy 2 more (with possible winner) ---\n";
    machine.insertQuarter();
    machine.turnCrank();
    machine.insertQuarter();
    machine.turnCrank();

    std::cout << "\n--- Test 6: try to buy when sold out ---\n";
    machine.insertQuarter();
    machine.turnCrank();

    std::cout << "\n--- Test 7: refill and buy again ---\n";
    machine.refill(2);
    machine.insertQuarter();
    machine.turnCrank();

    return 0;
}
