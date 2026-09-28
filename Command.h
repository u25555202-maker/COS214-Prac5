#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>

// Command participant (GoF Command pattern). Every operator action is
// represented as an object so the invoker (OperatorConsole) can queue,
// log, and undo them uniformly, without knowing what each action actually
// does or which receiver it targets.
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    // Default: most actions here are not reversible. Reported clearly
    // rather than silently doing nothing (see CancelCommand).
    virtual void undo() {
        std::cout << "[COMMAND] '" << description() << "' cannot be undone." << std::endl;
    }
    virtual std::string description() const = 0;
};

#endif
