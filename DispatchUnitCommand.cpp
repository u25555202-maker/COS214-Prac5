#include "DispatchUnitCommand.h"
#include "ResponseComponent.h"
#include "Incident.h"

DispatchUnitCommand::DispatchUnitCommand(ResponseComponent* unit, Incident* incident, std::string location)
    : unit(unit), incident(incident), location(std::move(location)) {}

void DispatchUnitCommand::execute() {
    incident->dispatch(); // State transition: Reported -> Dispatched
    unit->dispatchTo(location, incident);
}

std::string DispatchUnitCommand::description() const {
    return "Dispatch " + unit->getName() + " to " + location;
}
