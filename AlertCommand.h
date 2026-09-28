#ifndef ALERTCOMMAND_H
#define ALERTCOMMAND_H

#include "Command.h"
#include <string>

class CommunicationChannel;

// ConcreteCommand: sends an alert through whatever CommunicationChannel it
// is given -- the command has no idea a legacy pager adapter sits behind
// that interface.
class AlertCommand : public Command {
public:
    AlertCommand(CommunicationChannel* channel, std::string message, std::string location);
    void execute() override;
    std::string description() const override;

private:
    CommunicationChannel* channel; // receiver, non-owning
    std::string message;
    std::string location;
};

#endif
