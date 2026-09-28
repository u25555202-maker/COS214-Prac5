#include "CancelCommand.h"

CancelCommand::CancelCommand(Command* target) : target(target) {}

void CancelCommand::execute() {
    target->undo();
}

std::string CancelCommand::description() const {
    return "Cancel: " + target->description();
}
