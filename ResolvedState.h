#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

class ResolvedState : public IncidentState {
public:
    void dispatch(Incident* incident) override;
    void contain(Incident* incident) override;
    void resolve(Incident* incident) override;
    std::string name() const override { return "Resolved"; }
};

#endif
