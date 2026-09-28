#include "Dashboard.h"
#include "../Incident.h"
#include <iostream>
using namespace std;

void Dashboard::update(Incident* incident) {
    cout << "[DASHBOARD] Incident #" << incident->getId()
         << " (" << incident->getType() << " @ " << incident->getLocation()
         << ") is now: " << incident->getStatusName() << endl;
}
