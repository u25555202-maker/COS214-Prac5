#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "Observer.h"

// ConcreteObserver: simulates the control-room dashboard operators watch.
class Dashboard : public Observer {
public:
    void update(Subject* subject) override;
};

#endif
