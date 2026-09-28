<<<<<<< HEAD
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
=======
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
>>>>>>> 39611629a5ccbea14baf2605cfe4f7f23a4a00b5
