#include "IncidentCoordinator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include "../Incident.h"
#include <iostream>
using namespace std;

IncidentCoordinator::IncidentCoordinator()
    : security(nullptr), medical(nullptr), facilities(nullptr), commChannel(nullptr) {}

void IncidentCoordinator::registerSecurity(SecurityTeam* team) { security = team; }
void IncidentCoordinator::registerMedical(MedicalTeam* team) { medical = team; }
void IncidentCoordinator::registerFacilities(FacilitiesTeam* team) { facilities = team; }
void IncidentCoordinator::registerCommunicationChannel(CommunicationChannel* channel) { commChannel = channel; }

void IncidentCoordinator::componentArrived(ResponseComponent* comp, Incident* incident) {
    cout << "[COORDINATOR] " << comp->getName() << " reported arrival." << endl;

    if (comp == static_cast<ResponseComponent*>(security)) {
        // Security arriving on scene is the trigger: lock the area down
        // AND alert the medical team -- two colleagues coordinated as a
        // side effect of one colleague's event, without Security knowing
        // either of them exists.
        if (facilities) {
            facilities->lockdownArea(incident->getLocation());
        }
        if (commChannel) {
            commChannel->sendAlert(
                "Security on scene, area secured. Medical clearance requested.",
                incident->getLocation());
        }
    } else if (comp == static_cast<ResponseComponent*>(medical)) {
        cout << "[COORDINATOR] Medical on scene; awaiting facilities clearance." << endl;
    }
}

void IncidentCoordinator::componentFinished(ResponseComponent* comp, Incident* incident) {
    cout << "[COORDINATOR] " << comp->getName() << " reported task complete." << endl;

    if (comp == static_cast<ResponseComponent*>(facilities)) {
        // Facilities finishing an evacuation hands off to Medical.
        if (medical) {
            medical->treatCasualties(incident);
        }
    }
}
