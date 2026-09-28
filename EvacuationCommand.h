#ifndef EVACUATIONCOMMAND_H
#define EVACUATIONCOMMAND_H

#include "Command.h"
#include <string>

class FacilitiesTeam;
class Incident;

// ConcreteCommand: an operator-issued evacuation order. Triggers the
// receiver's behaviour, which in turn reports completion to the Mediator
// (FacilitiesTeam::evacuate calls componentFinished).
class EvacuationCommand : public Command {
public:
    EvacuationCommand(FacilitiesTeam* facilities, std::string area, Incident* incident);
    void execute() override;
    std::string description() const override;

private:
    FacilitiesTeam* facilities; // receiver, non-owning
    std::string area;
    Incident* incident; // non-owning
};

#endif
