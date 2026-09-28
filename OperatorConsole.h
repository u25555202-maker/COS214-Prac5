#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include "Command.h"
#include <vector>
#include <memory>

// Invoker (GoF Command pattern). The operator's single point of entry for
// issuing actions. Keeps a history of executed commands purely so
// CancelCommand has something concrete to target -- it has no knowledge of
// what any command actually does.
//
// Ownership: OperatorConsole OWNS every command it is given (unique_ptr in
// history) for the lifetime of the console, so undo/cancel can always
// reach back into history safely.
class OperatorConsole {
public:
    Command* submit(std::unique_ptr<Command> cmd);
    Command* lastCommand() const;

private:
    std::vector<std::unique_ptr<Command>> history;
};

#endif
