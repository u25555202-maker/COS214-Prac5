<<<<<<< HEAD
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "Observer.h"

// ConcreteObserver: simulates the control-room dashboard operators watch.
class Dashboard : public Observer {
public:
    void update(Subject* subject) override;
};

#endif
=======
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "Observer.h"

// ConcreteObserver: simulates the control-room dashboard operators watch.
class Dashboard : public Observer {
public:
    void update(Subject* subject) override;
};

#endif
>>>>>>> 39611629a5ccbea14baf2605cfe4f7f23a4a00b5
