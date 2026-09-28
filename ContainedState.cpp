#include "ContainedState.h"
#include "ResolvedState.h"
#include "../Incident.h"

void ContainedState::dispatch(Incident* incident) {
    incident->rejectTransition("dispatch");
}

void ContainedState::contain(Incident* incident) {
    incident->rejectTransition("contain");
}

void ContainedState::resolve(Incident* incident) {
    incident->setState(new ResolvedState());
}
