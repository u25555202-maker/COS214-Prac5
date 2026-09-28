#ifndef DISPATCHEDSTATE_H
#define DISPATCHEDSTATE_H

#include "IncidentState.h"

class DispatchedState : public IncidentState {
public:
    void dispatch(Incident* incident) override;
    void contain(Incident* incident) override;
    void resolve(Incident* incident) override;
    std::string name() const override { return "Dispatched"; }
};

#endif
