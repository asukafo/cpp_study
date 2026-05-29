#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "command.h"

// Invoker — stores commands and invokes them
class RemoteControl
{
public:
    RemoteControl(int slots = 7)
        : on_commands_(slots),
          off_commands_(slots),
          undo_command_(new NoCommand())
    {
        Command *no_cmd = new NoCommand();
        for (int i = 0; i < slots; ++i)
        {
            on_commands_[i] = no_cmd;
            off_commands_[i] = no_cmd;
        }
    }

    ~RemoteControl()
    {
        // Only delete the NoCommand prototypes once
        delete on_commands_[0];
    }

    void setCommand(int slot, Command *on_cmd, Command *off_cmd)
    {
        on_commands_[slot] = on_cmd;
        off_commands_[slot] = off_cmd;
    }

    void onButtonPressed(int slot)
    {
        on_commands_[slot]->execute();
        undo_command_ = on_commands_[slot];
    }

    void offButtonPressed(int slot)
    {
        off_commands_[slot]->execute();
        undo_command_ = off_commands_[slot];
    }

    void undoPressed()
    {
        std::cout << "--- UNDO ---" << std::endl;
        undo_command_->undo();
    }

    friend std::ostream &operator<<(std::ostream &os, const RemoteControl &rc)
    {
        os << "\n------ Remote Control ------\n";
        for (size_t i = 0; i < rc.on_commands_.size(); ++i)
            os << "[slot " << i << "] programmed\n";
        return os;
    }

private:
    std::vector<Command *> on_commands_;
    std::vector<Command *> off_commands_;
    Command *undo_command_;
};

#endif // REMOTE_CONTROL_H
