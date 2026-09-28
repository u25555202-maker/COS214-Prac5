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

static void banner(const string& text) {
    cout << "\n============================================================\n";
    cout << text << "\n";
    cout << "============================================================" << endl;
}

// ---------------------------------------------------------------------
// Story 1: a fire report driven entirely through the Facade.
// In a single call to reportEmergency(), the tutor can observe:
//   Facade    -> coordinates 4 subsystem operations in one entry point
//   Command   -> each of those operations is a Command run by the console
//   State     -> DispatchUnitCommand advances the Incident's state
//   Observer  -> Dashboard/AuditLogger react to every state change
//   Mediator  -> Security's arrival causes the coordinator to lock the
//                area via Facilities AND raise an alert
//   Adapter   -> that alert travels through LegacyPagerAdapter to the
//                incompatible LegacyPagerSystem
// All six patterns in one execution flow.
// ---------------------------------------------------------------------
void storyOne(EmergencyResponseFacade& facade) {
    banner("STORY 1: Fire reported in the Engineering Building");

    Incident* incident = facade.reportEmergency("Fire", "Engineering Building");

    cout << "\n-- Incident progresses through containment and resolution --" << endl;
    incident->contain();   // Dispatched -> Contained (valid)
    incident->dispatch();  // INVALID: already past Dispatched. Handled, not crashed.
    incident->resolve();   // Contained -> Resolved (valid)
    incident->resolve();   // INVALID: already Resolved. Handled, not crashed.
}

// ---------------------------------------------------------------------
// Story 2: an operator manually coordinating a medical evacuation,
// using the subsystem components directly (Command + Mediator + Adapter)
// WITHOUT going through the Facade -- showing every subsystem piece the
// Facade wraps in Story 1 remains independently usable on its own.
// Also demonstrates CancelCommand undoing a previous LockAreaCommand.
// ---------------------------------------------------------------------
void storyTwo(EmergencyResponseFacade& facade) {
    banner("STORY 2: Operator-driven evacuation (bypassing the Facade)");

    Dashboard dashboard;
    AuditLogger logger;
    Incident incident(99, "Gas Leak", "Chemistry Lab");
    incident.attach(&dashboard);
    incident.attach(&logger);
    incident.notify();

    OperatorConsole* console = facade.getConsole();

    // Operator locks the lab down directly via a Command (no Facade call).
    Command* lockCmd = console->submit(unique_ptr<Command>(
        new LockAreaCommand(facade.getAccessControl(), incident.getLocation())));

    // Operator orders an evacuation; FacilitiesTeam finishing hands off to
    // MedicalTeam through the Mediator (componentFinished chain).
    incident.dispatch(); // Reported -> Dispatched
    console->submit(unique_ptr<Command>(
        new EvacuationCommand(facade.getFacilities(), incident.getLocation(), &incident)));

    // Operator decides the lockdown is no longer needed and cancels it --
    // CancelCommand's receiver is another Command object.
    console->submit(unique_ptr<Command>(new CancelCommand(lockCmd)));

    // INVALID operation, handled sensibly: trying to resolve an incident
    // that has not yet been contained.
    incident.resolve();

    // Subsystem still independently usable outside any pattern wrapper.
    facade.getAccessControl()->restrictArea("Chemistry Storage Annex");

    incident.contain();
    incident.resolve();
}

int main() {
    EmergencyResponseFacade facade;

    storyOne(facade);
    storyTwo(facade);

    cout << "\n[MAIN] CampusGuard demonstration complete." << endl;
    return 0;
}
