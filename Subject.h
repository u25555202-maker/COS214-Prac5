#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

// Subject participant (GoF Observer pattern). Holds the list of attached
// observers and drives notification; a concrete subject inherits this and
// adds whatever state observers actually care about. Kept as its own class
// (rather than folded into Incident) so the mapping to GoF stays literal:
// Subject and ConcreteSubject are distinct classes, matching the reference
// UML.
class Subject {
public:
    virtual ~Subject() {}
    void attach(Observer* obs);
    void detach(Observer* obs);
    void notify();

private:
    std::vector<Observer*> observers; // non-owning: observers outlive individual subjects
};

#endif
