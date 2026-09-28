#include "ResolvedState.h"
#include "Incident.h"

void ResolvedState::dispatch(Incident* incident) {
    incident->rejectTransition("dispatch");
}

void ResolvedState::contain(Incident* incident) {
    incident->rejectTransition("contain");
}

void ResolvedState::resolve(Incident* incident) {
    incident->rejectTransition("resolve");
}
