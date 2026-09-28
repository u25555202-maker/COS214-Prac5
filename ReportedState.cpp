#include "ReportedState.h"
#include "DispatchedState.h"
#include "Incident.h"

void ReportedState::dispatch(Incident* incident) {
    incident->setState(new DispatchedState());
}

void ReportedState::contain(Incident* incident) {
    incident->rejectTransition("contain");
}

void ReportedState::resolve(Incident* incident) {
    incident->rejectTransition("resolve");
}
