#ifndef EMERGENCYRESPONSEFACADE_H
#define EMERGENCYRESPONSEFACADE_H

#include <memory>
#include <vector>
#include <string>

#include "Incident.h"
#include "AccessControlSystem.h"
#include "OperatorConsole.h"
#include "IncidentCoordinator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include "LegacyPagerAdapter.h"
#include "Dashboard.h"
#include "AuditLogger.h"

// Facade (GoF Facade pattern). Owns and wires up the whole subsystem
// (access control, response teams, mediator, communication adapter,
// console, observers) and exposes one high-level operation,
// reportEmergency(), that a client can call without knowing any of that
// wiring exists. Every subsystem piece it touches remains independently
// reachable (getConsole(), getAccessControl(), ...) for callers -- such as
// Story 2 in main.cpp -- who want to act directly instead of through the
// facade.
//
// Ownership: EmergencyResponseFacade is the single owner of every
// subsystem object below (all unique_ptr) and of every Incident it creates.
// Everything else in the system (Mediator, Commands, Colleagues) only ever
// holds non-owning raw pointers into these objects.
class EmergencyResponseFacade {
public:
    EmergencyResponseFacade();
    ~EmergencyResponseFacade();

    // High-level workflow: register the incident, dispatch security and
    // medical, lock the area down, and raise the external alert -- five
    // subsystem operations behind one call.
    Incident* reportEmergency(const std::string& type, const std::string& location);

    // Subsystem access kept independently usable.
    OperatorConsole* getConsole() { return console.get(); }
    AccessControlSystem* getAccessControl() { return accessControl.get(); }
    FacilitiesTeam* getFacilities() { return facilities.get(); }
    MedicalTeam* getMedical() { return medical.get(); }
    SecurityTeam* getSecurity() { return security.get(); }
    CommunicationChannel* getCommChannel() { return commChannel.get(); }

private:
    int nextIncidentId;
    std::vector<std::unique_ptr<Incident>> incidents;

    std::unique_ptr<AccessControlSystem> accessControl;
    std::unique_ptr<IncidentCoordinator> mediator;
    std::unique_ptr<SecurityTeam> security;
    std::unique_ptr<MedicalTeam> medical;
    std::unique_ptr<FacilitiesTeam> facilities;
    std::unique_ptr<LegacyPagerAdapter> commChannel;
    std::unique_ptr<OperatorConsole> console;
    std::unique_ptr<Dashboard> dashboard;
    std::unique_ptr<AuditLogger> auditLogger;
};

#endif
