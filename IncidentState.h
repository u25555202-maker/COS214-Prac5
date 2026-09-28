#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>
class Incident;

// State participant (GoF State pattern).
// Incident delegates status-transition requests to its current state object
// instead of using a status enum + a big switch/if-chain. Each concrete
// state decides which transitions are legal from itself, and rejects the
// rest sensibly (Functional Requirement: at least one invalid-operation
// case handled, not silently ignored).
class IncidentState {
public:
    virtual ~IncidentState() {}
    virtual void dispatch(Incident* incident) = 0;
    virtual void contain(Incident* incident) = 0;
    virtual void resolve(Incident* incident) = 0;
    virtual std::string name() const = 0;
};

#endif
