#ifndef COMMAND_H
#define COMMAND_H

// Interface — Command
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Null Object for safe initialization
class NoCommand : public Command
{
public:
    void execute() override {}
    void undo() override {}
};

#endif // COMMAND_H
