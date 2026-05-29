#include <iostream>

#include "command.h"
#include "light.h"
#include "light_commands.h"
#include "remote_control.h"

// MacroCommand — bundles multiple commands to execute/undo together
class MacroCommand : public Command
{
public:
    MacroCommand() = default;

    ~MacroCommand()
    {
        for (Command *cmd : commands_)
            delete cmd;
    }

    void add(Command *cmd) { commands_.push_back(cmd); }

    void execute() override
    {
        for (Command *cmd : commands_)
            cmd->execute();
    }

    void undo() override
    {
        for (auto it = commands_.rbegin(); it != commands_.rend(); ++it)
            (*it)->undo();
    }

private:
    std::vector<Command *> commands_;
};

int main()
{
    std::cout << "The Command Pattern encapsulates a request as an object,\n"
              << "thereby letting you parameterize other objects with different\n"
              << "requests, queue or log requests, and support undoable operations.\n"
              << std::endl;

    std::cout << "=== Command Pattern: Remote Control ===" << std::endl;

    RemoteControl remote;

    Light *living_room_light = new Light("Living Room");
    Light *kitchen_light = new Light("Kitchen");

    LightOnCommand *living_room_on = new LightOnCommand(living_room_light);
    LightOffCommand *living_room_off = new LightOffCommand(living_room_light);
    LightOnCommand *kitchen_on = new LightOnCommand(kitchen_light);
    LightOffCommand *kitchen_off = new LightOffCommand(kitchen_light);

    remote.setCommand(0, living_room_on, living_room_off);
    remote.setCommand(1, kitchen_on, kitchen_off);

    std::cout << remote << std::endl;

    std::cout << "\n--- Testing button presses ---\n";
    remote.onButtonPressed(0);
    remote.offButtonPressed(0);
    remote.undoPressed();

    remote.onButtonPressed(1);
    remote.offButtonPressed(1);

    std::cout << "\n--- Macro Command: Party Mode ---\n";
    MacroCommand *party_on = new MacroCommand();
    party_on->add(new LightOnCommand(living_room_light));
    party_on->add(new LightOnCommand(kitchen_light));

    MacroCommand *party_off = new MacroCommand();
    party_off->add(new LightOffCommand(living_room_light));
    party_off->add(new LightOffCommand(kitchen_light));

    remote.setCommand(2, party_on, party_off);
    remote.onButtonPressed(2);
    remote.undoPressed();

    delete living_room_light;
    delete kitchen_light;

    return 0;
}
