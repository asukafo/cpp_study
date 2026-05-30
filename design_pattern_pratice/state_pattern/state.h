#ifndef STATE_H
#define STATE_H

#include <iostream>

// Forward declaration
class GumballMachine;

// State — interface encapsulating state-specific behavior
class State
{
public:
    virtual ~State() = default;

    virtual void insertQuarter()  { std::cout << "  [nop] can't do that\n"; }
    virtual void ejectQuarter()   { std::cout << "  [nop] can't do that\n"; }
    virtual void turnCrank()      { std::cout << "  [nop] can't do that\n"; }
    virtual void dispense()       { std::cout << "  [nop] can't do that\n"; }
};

#endif // STATE_H
