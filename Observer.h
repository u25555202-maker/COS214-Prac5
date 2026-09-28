#ifndef OBSERVER_H
#define OBSERVER_H

class Incident; // forward declaration

// Observer participant (GoF Observer pattern).
// Decouples Incident (the subject) from whoever needs to react to status
// changes -- a control-room dashboard, an audit log, potentially more in
// future without Incident ever knowing about them by name.
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(Incident* incident) = 0;
};

#endif
