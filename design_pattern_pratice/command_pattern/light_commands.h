#ifndef LIGHT_COMMANDS_H
#define LIGHT_COMMANDS_H

#include "command.h"
#include "light.h"

// ConcreteCommand — turns light on
class LightOnCommand : public Command
{
public:
    explicit LightOnCommand(Light *light) : light_(light) {}

    void execute() override { light_->on(); }
    void undo() override { light_->off(); }

private:
    Light *light_;
};

// ConcreteCommand — turns light off
class LightOffCommand : public Command
{
public:
    explicit LightOffCommand(Light *light) : light_(light) {}

    void execute() override { light_->off(); }
    void undo() override { light_->on(); }

private:
    Light *light_;
};

#endif // LIGHT_COMMANDS_H
