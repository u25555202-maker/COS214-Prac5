#include "FacilitiesTeam.h"
#include "Incident.h"
#include <iostream>
using namespace std;

FacilitiesTeam::FacilitiesTeam(string name, ResponseMediator* mediator, AccessControlSystem* access)
    : ResponseComponent(std::move(name), mediator), access(access) {}

void FacilitiesTeam::lockdownArea(const string& area) {
    cout << "[" << name << "] Initiating lockdown of " << area << endl;
    access->lockArea(area);
}

void FacilitiesTeam::evacuate(const string& area, Incident* incident) {
    cout << "[" << name << "] Evacuating " << area
         << " for incident #" << incident->getId() << endl;
    access->unlockArea(area); // open exits
    if (mediator) {
        mediator->componentFinished(this, incident);
    }
}
