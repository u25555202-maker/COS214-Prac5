#include "SecurityTeam.h"

SecurityTeam::SecurityTeam(std::string name, ResponseMediator* mediator)
    : ResponseComponent(std::move(name), mediator) {}
