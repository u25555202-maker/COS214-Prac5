#include "DispatchedState.h"
#include "ContainedState.h"
#include "Incident.h"

void DispatchedState::dispatch(Incident* incident) {
    incident->rejectTransition("dispatch");
}

void DispatchedState::contain(Incident* incident) {
    incident->setState(new ContainedState());
}

void DispatchedState::resolve(Incident* incident) {
    incident->rejectTransition("resolve");
}
