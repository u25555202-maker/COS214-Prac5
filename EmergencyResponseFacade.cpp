#include "EmergencyResponseFacade.h"
#include "DispatchUnitCommand.h"
#include "LockAreaCommand.h"
#include "AlertCommand.h"
#include <iostream>
using namespace std;

EmergencyResponseFacade::EmergencyResponseFacade() : nextIncidentId(1) {
    accessControl.reset(new AccessControlSystem());
    mediator.reset(new IncidentCoordinator());

    security.reset(new SecurityTeam("Campus Security Alpha", mediator.get()));
    medical.reset(new MedicalTeam("Medical Response Team", mediator.get()));
    facilities.reset(new FacilitiesTeam("Facilities Crew", mediator.get(), accessControl.get()));

    mediator->registerSecurity(security.get());
    mediator->registerMedical(medical.get());
    mediator->registerFacilities(facilities.get());

    commChannel.reset(new LegacyPagerAdapter(unique_ptr<LegacyPagerSystem>(new LegacyPagerSystem())));
    mediator->registerCommunicationChannel(commChannel.get());

    console.reset(new OperatorConsole());
    dashboard.reset(new Dashboard());
    auditLogger.reset(new AuditLogger());
}

EmergencyResponseFacade::~EmergencyResponseFacade() {}

Incident* EmergencyResponseFacade::reportEmergency(const string& type, const string& location) {
    // Subsystem operation 1: register the incident and attach observers.
    incidents.push_back(unique_ptr<Incident>(new Incident(nextIncidentId++, type, location)));
    Incident* incident = incidents.back().get();
    incident->attach(dashboard.get());
    incident->attach(auditLogger.get());
    incident->notify(); // announce the initial "Reported" state

    cout << "\n[FACADE] --- reportEmergency(" << type << ", " << location << ") ---" << endl;

    // Subsystem operation 2: dispatch security (Command -> State -> Mediator chain).
    console->submit(unique_ptr<Command>(
        new DispatchUnitCommand(security.get(), incident, location)));

    // Subsystem operation 3: dispatch medical.
    console->submit(unique_ptr<Command>(
        new DispatchUnitCommand(medical.get(), incident, location)));

    // Subsystem operation 4: an explicit lockdown command in addition to
    // whatever the mediator triggered as a side effect of security's arrival.
    console->submit(unique_ptr<Command>(
        new LockAreaCommand(accessControl.get(), location)));

    // Subsystem operation 5: raise the external alert through the adapter.
    console->submit(unique_ptr<Command>(
        new AlertCommand(commChannel.get(),
                          "Emergency reported: " + type,
                          location)));

    return incident;
}
