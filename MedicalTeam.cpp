#include "MedicalTeam.h"
#include "../Incident.h"
#include <iostream>
using namespace std;

MedicalTeam::MedicalTeam(string name, ResponseMediator* mediator)
    : ResponseComponent(std::move(name), mediator) {}

void MedicalTeam::treatCasualties(Incident* incident) {
    cout << "[" << name << "] Treating casualties for incident #"
         << incident->getId() << endl;
    if (mediator) {
        mediator->componentFinished(this, incident);
    }
}
