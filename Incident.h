#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include <vector>
#include <memory>
#include "State/IncidentState.h"
#include "Observer/Observer.h"

// Incident plays two GoF roles at once (Rule 7 explicitly allows this
// where genuinely justified):
//   - State Context: delegates status transitions to the current
//     IncidentState and swaps state objects as the incident progresses.
//   - Observer Subject: notifies attached observers whenever its status
//     changes, without knowing whether that's a Dashboard, an AuditLogger,
//     both, or something added later.
//
// Ownership: Incident OWNS its current IncidentState (unique_ptr) -- states
// are cheap, incident-specific, and never shared. Incident does NOT own its
// Observers (raw, non-owning pointers) -- observers outlive individual
// incidents and are shared across many incidents (e.g. one Dashboard for
// the whole campus).
class Incident {
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

    // Observer subject responsibilities.
    void attach(Observer* obs);
    void detach(Observer* obs);
    void notify();

private:
    int id;
    std::string type;
    std::string location;
    std::unique_ptr<IncidentState> state;
    std::vector<Observer*> observers;
};

#endif
