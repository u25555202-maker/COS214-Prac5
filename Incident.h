#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include <memory>
#include "IncidentState.h"
#include "Subject.h"

// Incident plays two GoF roles at once (Rule 7 explicitly allows this
// where genuinely justified):
//   - State Context: delegates status transitions to the current
//     IncidentState and swaps state objects as the incident progresses.
//   - ConcreteSubject: inherits Subject's attach()/detach()/notify() and
//     adds the state observers actually care about (status, id, type,
//     location), without knowing whether an observer is a Dashboard, an
//     AuditLogger, or something added later.
//
// Ownership: Incident OWNS its current IncidentState (unique_ptr) -- states
// are cheap, incident-specific, and never shared. The observer list itself
// lives in Subject and remains non-owning there -- observers outlive
// individual incidents and are shared across many of them (e.g. one
// Dashboard for the whole campus).
class Incident : public Subject {
public:
    Incident(int id, std::string type, std::string location);
    ~Incident();

    // State transition requests -- delegated to the current state.
    void dispatch();
    void contain();
    void resolve();

    // Called only by IncidentState subclasses to move to the next state.
    void setState(IncidentState* newState);

    // Used by a state to reject an illegal transition without crashing.
    void rejectTransition(const std::string& attempted) const;

    int getId() const { return id; }
    std::string getType() const { return type; }
    std::string getLocation() const { return location; }
    std::string getStatusName() const { return state->name(); }

private:
    int id;
    std::string type;
    std::string location;
    std::unique_ptr<IncidentState> state;
};

#endif
