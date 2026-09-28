#include "OperatorConsole.h"
#include <iostream>
using namespace std;

Command* OperatorConsole::submit(unique_ptr<Command> cmd) {
    cout << "[CONSOLE] Executing: " << cmd->description() << endl;
    cmd->execute();
    history.push_back(std::move(cmd));
    return history.back().get();
}

Command* OperatorConsole::lastCommand() const {
    if (history.empty()) return nullptr;
    return history.back().get();
}
