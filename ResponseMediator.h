#ifndef RESPONSEMEDIATOR_H
#define RESPONSEMEDIATOR_H

class ResponseComponent;
class Incident;

// Mediator interface (GoF Mediator pattern). Colleagues report events here
// instead of calling one another directly, so adding or changing a
// response team never requires touching the other teams.
class ResponseMediator {
public:
    virtual ~ResponseMediator() {}
    virtual void componentArrived(ResponseComponent* comp, Incident* incident) = 0;
    virtual void componentFinished(ResponseComponent* comp, Incident* incident) = 0;
};

#endif
