#ifndef CANCELCOMMAND_H
#define CANCELCOMMAND_H

#include "Command.h"

// ConcreteCommand: cancels a previously issued command by invoking its
// undo(). Demonstrates a command that operates on another command as its
// receiver -- and surfaces the invalid-operation case sensibly when the
// target command was never reversible in the first place (Command::undo's
// default behaviour above).
class CancelCommand : public Command {
public:
    explicit CancelCommand(Command* target);
    void execute() override;
    std::string description() const override;

private:
    Command* target; // non-owning: owned by OperatorConsole's history
};

#endif
