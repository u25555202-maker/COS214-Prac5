#include "AuditLogger.h"
#include "../Incident.h"
#include <iostream>
using namespace std;

void AuditLogger::update(Incident* incident) {
    cout << "[AUDIT] status-change event: incident=" << incident->getId()
         << " newState=" << incident->getStatusName() << endl;
}
