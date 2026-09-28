#ifndef CONTAINEDSTATE_H
#define CONTAINEDSTATE_H

#include "IncidentState.h"

class ContainedState : public IncidentState {
public:
    void dispatch(Incident* incident) override;
    void contain(Incident* incident) override;
    void resolve(Incident* incident) override;
    std::string name() const override { return "Contained"; }
};

#endif
