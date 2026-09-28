#ifndef AUDITLOGGER_H
#define AUDITLOGGER_H

#include "Observer.h"

// ConcreteObserver: writes an audit trail of every status change.
// Independent of Dashboard -- adding/removing one never affects the other,
// which is the point of Observer over Incident calling both directly.
class AuditLogger : public Observer {
public:
    void update(Subject* subject) override;
};

#endif
