#include "gumball_machine.h"
#include "concrete_states.h"

GumballMachine::GumballMachine(int count)
    : count_(count),
      no_quarter_state_(new NoQuarterState(this)),
      has_quarter_state_(new HasQuarterState(this)),
      sold_state_(new SoldState(this)),
      sold_out_state_(new SoldOutState(this)),
      winner_state_(new WinnerState(this))
{
    state_ = (count > 0) ? no_quarter_state_ : sold_out_state_;
}

GumballMachine::~GumballMachine()
{
    delete no_quarter_state_;
    delete has_quarter_state_;
    delete sold_state_;
    delete sold_out_state_;
    delete winner_state_;
}

void GumballMachine::releaseBall()
{
    std::cout << "A gumball comes rolling out..." << std::endl;
    if (count_ > 0) --count_;
}

void GumballMachine::refill(int count)
{
    count_ += count;
    std::cout << "Refilled. Count: " << count_ << std::endl;
    if (count_ > 0)
        setState(no_quarter_state_);
}
