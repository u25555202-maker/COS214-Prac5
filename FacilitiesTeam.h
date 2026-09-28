#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H

#include "ResponseComponent.h"
#include "AccessControlSystem.h"

// FacilitiesTeam is a Mediator colleague AND a client of the
// AccessControlSystem subsystem service. It is the component the
// IncidentCoordinator (Mediator) turns to when a building lockdown is
// needed as a side effect of another team's action.
class FacilitiesTeam : public ResponseComponent {
public:
    FacilitiesTeam(std::string name, ResponseMediator* mediator, AccessControlSystem* access);
    void lockdownArea(const std::string& area);
    void evacuate(const std::string& area, Incident* incident);

private:
    AccessControlSystem* access; // non-owning: owned by the Facade
};

#endif
