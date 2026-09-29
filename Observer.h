#ifndef OBSERVER_H
#define OBSERVER_H

class Subject; // forward declaration

// Observer participant (GoF Observer pattern).
// Decouples Subject (the subject) from whoever needs to react to status
// changes -- a control-room dashboard, an audit log, potentially more in
// future without Subject ever knowing about them by name.
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(Subject* subject) = 0;
};

#endif
