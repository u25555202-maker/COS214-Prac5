<<<<<<< HEAD
#include "AuditLogger.h"
#include "Incident.h"
#include <iostream>
using namespace std;

void AuditLogger::update(Subject* subject) {
    Incident* incident = static_cast<Incident*>(subject);
    cout << "[AUDIT] status-change event: incident=" << incident->getId()
         << " newState=" << incident->getStatusName() << endl;
}
=======
#include "AuditLogger.h"
#include "Incident.h"
#include <iostream>
using namespace std;

void AuditLogger::update(Subject* subject) {
    Incident* incident = static_cast<Incident*>(subject);
    cout << "[AUDIT] status-change event: incident=" << incident->getId()
         << " newState=" << incident->getStatusName() << endl;
}
>>>>>>> 39611629a5ccbea14baf2605cfe4f7f23a4a00b5
