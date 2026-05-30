#ifndef CONCRETE_STATES_H
#define CONCRETE_STATES_H

#include <cstdlib>

#include "state.h"

class GumballMachine;

// --- NoQuarterState ---
class NoQuarterState : public State
{
public:
    explicit NoQuarterState(GumballMachine *machine) : machine_(machine) {}

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;

private:
    GumballMachine *machine_;
};

// --- HasQuarterState ---
class HasQuarterState : public State
{
public:
    explicit HasQuarterState(GumballMachine *machine) : machine_(machine) {}

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;

private:
    GumballMachine *machine_;
};

// --- SoldState ---
class SoldState : public State
{
public:
    explicit SoldState(GumballMachine *machine) : machine_(machine) {}

    void dispense() override;

private:
    GumballMachine *machine_;
};

// --- SoldOutState ---
class SoldOutState : public State
{
public:
    explicit SoldOutState(GumballMachine * /*machine*/) {}

    void insertQuarter() override;
};

// --- WinnerState (bonus: 2 gumballs) ---
class WinnerState : public State
{
public:
    explicit WinnerState(GumballMachine *machine) : machine_(machine) {}

    void dispense() override;

private:
    GumballMachine *machine_;
};

#endif // CONCRETE_STATES_H
