#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include <string>

// A campus subsystem service: building access control. Used directly as a
// Command receiver (LockAreaCommand) and also invoked from within
// IncidentCoordinator (Mediator) and EmergencyResponseFacade (Facade).
// It stays independently usable -- nothing here depends on the patterns
// wrapping it.
class AccessControlSystem {
public:
    virtual ~AccessControlSystem() {}
    virtual void lockArea(const std::string& area);
    virtual void unlockArea(const std::string& area);
    virtual void restrictArea(const std::string& area);
};

#endif
