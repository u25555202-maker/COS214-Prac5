#include "EvacuationCommand.h"
#include "FacilitiesTeam.h"

EvacuationCommand::EvacuationCommand(FacilitiesTeam* facilities, std::string area, Incident* incident)
    : facilities(facilities), area(std::move(area)), incident(incident) {}

void EvacuationCommand::execute() {
    facilities->evacuate(area, incident);
}

std::string EvacuationCommand::description() const {
    return "Evacuate " + area;
}
