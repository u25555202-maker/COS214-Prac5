#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include <string>

class ResponseComponent;
class Incident;

// ConcreteCommand: dispatches a response unit (receiver) to a location for
// a given incident. Advances the incident's State as a side effect and,
// through the receiver's own logic, reports arrival to the Mediator.
class DispatchUnitCommand : public Command {
public:
    DispatchUnitCommand(ResponseComponent* unit, Incident* incident, std::string location);
    void execute() override;
    std::string description() const override;

private:
    ResponseComponent* unit; // receiver, non-owning
    Incident* incident;      // non-owning
    std::string location;
};

#endif
