#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

#include "ResponseMediator.h"
#include "CommunicationChannel.h"

class SecurityTeam;
class MedicalTeam;
class FacilitiesTeam;

// ConcreteMediator (GoF Mediator pattern). Holds references to all
// colleagues and to the communication channel (via the Adapter's target
// interface -- the mediator never knows a legacy pager exists underneath).
// This is where the "one team's action causes coordinated behaviour in
// others" requirement lives: SecurityTeam arriving on scene causes
// FacilitiesTeam to lock the area down AND an alert to go out.
//
// Ownership: IncidentCoordinator does not own any of the colleagues, the
// access system, or the communication channel -- all are owned by
// EmergencyResponseFacade and merely referenced here (non-owning raw
// pointers), since the mediator's job is coordination, not lifetime
// management.
class IncidentCoordinator : public ResponseMediator {
public:
    IncidentCoordinator();

    void registerSecurity(SecurityTeam* team);
    void registerMedical(MedicalTeam* team);
    void registerFacilities(FacilitiesTeam* team);
    void registerCommunicationChannel(CommunicationChannel* channel);

    void componentArrived(ResponseComponent* comp, Incident* incident) override;
    void componentFinished(ResponseComponent* comp, Incident* incident) override;

private:
    SecurityTeam* security;
    MedicalTeam* medical;
    FacilitiesTeam* facilities;
    CommunicationChannel* commChannel;
};

#endif
