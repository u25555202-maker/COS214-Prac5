<<<<<<< HEAD
#include "Dashboard.h"
#include "Incident.h"
#include <iostream>
using namespace std;

void Dashboard::update(Subject* subject) {
    // Safe here because Incident is currently CampusGuard's only
    // ConcreteSubject; if a second one is ever added, this cast would need
    // to become a real type check (e.g. dynamic_cast + a null check).
    Incident* incident = static_cast<Incident*>(subject);
    cout << "[DASHBOARD] Incident #" << incident->getId()
         << " (" << incident->getType() << " @ " << incident->getLocation()
         << ") is now: " << incident->getStatusName() << endl;
}
=======
#include "Dashboard.h"
#include "Incident.h"
#include <iostream>
using namespace std;

void Dashboard::update(Subject* subject) {
    // Safe here because Incident is currently CampusGuard's only
    // ConcreteSubject; if a second one is ever added, this cast would need
    // to become a real type check (e.g. dynamic_cast + a null check).
    Incident* incident = static_cast<Incident*>(subject);
    cout << "[DASHBOARD] Incident #" << incident->getId()
         << " (" << incident->getType() << " @ " << incident->getLocation()
         << ") is now: " << incident->getStatusName() << endl;
}
>>>>>>> 39611629a5ccbea14baf2605cfe4f7f23a4a00b5
