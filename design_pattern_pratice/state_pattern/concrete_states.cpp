#include "concrete_states.h"
#include "gumball_machine.h"

// --- NoQuarterState ---
void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter." << std::endl;
    machine_->setState(machine_->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "No quarter to eject." << std::endl;
}

void NoQuarterState::turnCrank()
{
    std::cout << "You turned, but there's no quarter." << std::endl;
}

// --- HasQuarterState ---
void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter." << std::endl;
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned." << std::endl;
    machine_->setState(machine_->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
    std::cout << "You turned the crank..." << std::endl;
    // 10% chance of being a winner (2 gumballs instead of 1)
    int winner = rand() % 10;
    if (winner == 0 && machine_->getCount() > 1)
    {
        machine_->setState(machine_->getWinnerState());
    }
    else
    {
        machine_->setState(machine_->getSoldState());
    }
}

// --- SoldState ---
void SoldState::dispense()
{
    machine_->releaseBall();
    if (machine_->getCount() > 0)
    {
        machine_->setState(machine_->getNoQuarterState());
    }
    else
    {
        std::cout << "Oops, out of gumballs!" << std::endl;
        machine_->setState(machine_->getSoldOutState());
    }
}

// --- SoldOutState ---
void SoldOutState::insertQuarter()
{
    std::cout << "Machine is sold out." << std::endl;
}

// --- WinnerState ---
void WinnerState::dispense()
{
    std::cout << "🎉 WINNER! You get two gumballs!" << std::endl;
    machine_->releaseBall();
    if (machine_->getCount() == 0)
    {
        machine_->setState(machine_->getSoldOutState());
        std::cout << "Oops, out of gumballs after the first one!" << std::endl;
    }
    else
    {
        machine_->releaseBall();
        if (machine_->getCount() > 0)
        {
            machine_->setState(machine_->getNoQuarterState());
        }
        else
        {
            machine_->setState(machine_->getSoldOutState());
        }
    }
}
