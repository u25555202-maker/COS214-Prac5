#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H

#include <string>
#include "ResponseMediator.h"

class Incident;

// Colleague base (GoF Mediator pattern). Every response team knows its
// mediator but has NO knowledge of the other teams -- all cross-team
// coordination is delegated to the mediator via componentArrived/
// componentFinished.
class ResponseComponent {
public:
    ResponseComponent(std::string name, ResponseMediator* mediator);
    virtual ~ResponseComponent() {}

    // Domain action: a unit is sent to a location for an incident. This is
    // the Command pattern's receiver-side behaviour (DispatchUnitCommand
    // calls this), and internally it reports arrival to the mediator.
    virtual void dispatchTo(const std::string& location, Incident* incident);

    std::string getName() const { return name; }

protected:
    std::string name;
    ResponseMediator* mediator; // non-owning: mediator's lifetime is managed by the Facade
};

#endif
