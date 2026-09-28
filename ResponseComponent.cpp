#include "ResponseComponent.h"
#include "Incident.h"
#include <iostream>
using namespace std;

ResponseComponent::ResponseComponent(string name, ResponseMediator* mediator)
    : name(std::move(name)), mediator(mediator) {}

void ResponseComponent::dispatchTo(const string& location, Incident* incident) {
    cout << "[" << name << "] Arriving at " << location
         << " for incident #" << incident->getId() << endl;
    if (mediator) {
        mediator->componentArrived(this, incident);
    }
}
