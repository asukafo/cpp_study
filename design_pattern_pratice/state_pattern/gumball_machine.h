#ifndef GUMBALL_MACHINE_H
#define GUMBALL_MACHINE_H

#include <iostream>

#include "state.h"

// Context — holds the current state and delegates to it
class GumballMachine
{
public:
    explicit GumballMachine(int count);
    ~GumballMachine();

    // Actions — delegated to current state
    void insertQuarter() { state_->insertQuarter(); }
    void ejectQuarter()  { state_->ejectQuarter(); }
    void turnCrank()     { state_->turnCrank(); state_->dispense(); }

    // State management
    void setState(State *state) { state_ = state; }

    State *getHasQuarterState() const { return has_quarter_state_; }
    State *getNoQuarterState()  const { return no_quarter_state_; }
    State *getSoldState()       const { return sold_state_; }
    State *getSoldOutState()    const { return sold_out_state_; }
    State *getWinnerState()     const { return winner_state_; }

    // Gumball inventory
    int  getCount() const { return count_; }
    void releaseBall();
    void refill(int count);

    friend std::ostream &operator<<(std::ostream &os, const GumballMachine &gm)
    {
        os << "Gumball Machine [count=" << gm.count_ << "]";
        return os;
    }

private:
    State *state_;
    int count_;

    // State instances owned by the machine
    State *no_quarter_state_;
    State *has_quarter_state_;
    State *sold_state_;
    State *sold_out_state_;
    State *winner_state_;
};

#endif // GUMBALL_MACHINE_H
