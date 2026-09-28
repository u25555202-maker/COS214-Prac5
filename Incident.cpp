<<<<<<< HEAD
#include "Incident.h"
#include "ReportedState.h"
#include <iostream>
using namespace std;

Incident::Incident(int id, string type, string location)
    : id(id), type(std::move(type)), location(std::move(location)),
      state(new ReportedState()) {}

Incident::~Incident() {}

void Incident::dispatch() { state->dispatch(this); }
void Incident::contain()  { state->contain(this); }
void Incident::resolve()  { state->resolve(this); }

void Incident::setState(IncidentState* newState) {
    state.reset(newState);
    notify();
}

void Incident::rejectTransition(const string& attempted) const {
    cout << "[INCIDENT #" << id << "] REJECTED: cannot '" << attempted
         << "' while in state '" << state->name() << "'" << endl;
}
=======
#include "Incident.h"
#include "ReportedState.h"
#include <iostream>
using namespace std;

Incident::Incident(int id, string type, string location)
    : id(id), type(std::move(type)), location(std::move(location)),
      state(new ReportedState()) {}

Incident::~Incident() {}

void Incident::dispatch() { state->dispatch(this); }
void Incident::contain()  { state->contain(this); }
void Incident::resolve()  { state->resolve(this); }

void Incident::setState(IncidentState* newState) {
    state.reset(newState);
    notify();
}

void Incident::rejectTransition(const string& attempted) const {
    cout << "[INCIDENT #" << id << "] REJECTED: cannot '" << attempted
         << "' while in state '" << state->name() << "'" << endl;
}
>>>>>>> 39611629a5ccbea14baf2605cfe4f7f23a4a00b5
