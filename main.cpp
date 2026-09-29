#include <iostream>
#include <memory>

#include "EmergencyResponseFacade.h"
#include "LockAreaCommand.h"
#include "EvacuationCommand.h"
#include "CancelCommand.h"
#include "OperatorConsole.h"
#include "Incident.h"
#include "Dashboard.h"
#include "AuditLogger.h"

using namespace std;



// Scenario 1: Fire emergency using the facade
// ============================================================
void storyOne(EmergencyResponseFacade& facade) {

    cout << "STORY 1: Fire in the Engineering Building" << endl;

    // The Facade performs the complete emergency workflow.
    Incident* incident =
        facade.reportEmergency("Fire", "Engineering Building");

    cout << "\n-- Incident response continues --" << endl;

    // Valid state transitions.
    incident->contain();   // Dispatched -> Contained
    incident->resolve();   // Contained -> Resolved

    // Invalid operation handled safely.
    cout << "\n-- Attempting invalid operation --" << endl;
    incident->resolve();   // Already Resolved -> rejected
}


/// Scenario 2: Gas leak handled directly by the operator
// ============================================================
void storyTwo(EmergencyResponseFacade& facade) {

    cout << "STORY 2: Gas Leak Evacuation in the Chemistry Lab" << endl;

    // A second incident with different runtime data.
    Incident incident(99, "Gas Leak", "Chemistry Lab");

    // Observer pattern.
    Dashboard dashboard;
    AuditLogger logger;

    //add observers
    incident.attach(&dashboard);
    incident.attach(&logger);
    incident.notify();

    OperatorConsole* console = facade.getConsole();

    cout << "\n-- Operator locks the affected area --" << endl;

    // Command pattern:
    // OperatorConsole = Invoker
    // LockAreaCommand = ConcreteCommand
    // AccessControlSystem = Receiver
    Command* lockCommand =
        console->submit(
            unique_ptr<Command>(
                new LockAreaCommand(
                    facade.getAccessControl(),
                    incident.getLocation()
                )
            )
        );

    cout << "\n-- Incident is dispatched --" << endl;

    // State: Reported -> Dispatched
    incident.dispatch();

    cout << "\n-- Operator orders evacuation --" << endl;

    // Command -> FacilitiesTeam -> Mediator -> MedicalTeam
    console->submit(
        unique_ptr<Command>(
            new EvacuationCommand(
                facade.getFacilities(),
                incident.getLocation(),
                &incident
            )
        )
    );

    cout << "\n-- Operator cancels the previous lockdown --" << endl;

    // CancelCommand calls undo() on the previous LockAreaCommand.
    console->submit(
        unique_ptr<Command>(
            new CancelCommand(lockCommand)
        )
    );

    cout << "\n-- Attempting invalid state transition --" << endl;

    // Cannot resolve while only Dispatched.
    incident.resolve();

    cout << "\n-- Incident is contained and resolved correctly --" << endl;

    incident.contain();    // Dispatched -> Contained
    incident.resolve();    // Contained -> Resolved
}


int main() {

    EmergencyResponseFacade facade;

    storyOne(facade);
    storyTwo(facade);

    cout << "\n============================================================\n";
    cout << "CampusGuard demonstration complete." << endl;
    cout << "============================================================\n";

    return 0;
}