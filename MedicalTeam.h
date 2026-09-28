#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "ResponseComponent.h"

class MedicalTeam : public ResponseComponent {
public:
    MedicalTeam(std::string name, ResponseMediator* mediator);
    void treatCasualties(Incident* incident);
};

#endif
