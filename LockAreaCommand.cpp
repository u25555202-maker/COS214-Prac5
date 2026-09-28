#include "LockAreaCommand.h"
#include "AccessControlSystem.h"

LockAreaCommand::LockAreaCommand(AccessControlSystem* access, std::string area)
    : access(access), area(std::move(area)) {}

void LockAreaCommand::execute() {
    access->lockArea(area);
}

void LockAreaCommand::undo() {
    access->unlockArea(area);
}

std::string LockAreaCommand::description() const {
    return "Lock area " + area;
}
