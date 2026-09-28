#ifndef LOCKAREACOMMAND_H
#define LOCKAREACOMMAND_H

#include "Command.h"
#include <string>

class AccessControlSystem;

// ConcreteCommand: a reversible building-access action. Demonstrates
// undo(), which CancelCommand relies on.
class LockAreaCommand : public Command {
public:
    LockAreaCommand(AccessControlSystem* access, std::string area);
    void execute() override;
    void undo() override;
    std::string description() const override;

private:
    AccessControlSystem* access; // receiver, non-owning
    std::string area;
};

#endif
