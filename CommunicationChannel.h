#ifndef COMMUNICATIONCHANNEL_H
#define COMMUNICATIONCHANNEL_H

#include <string>

// Target interface (GoF Adapter pattern). This is the interface every part
// of CampusGuard (commands, mediator, facade) is written against. It knows
// nothing about how alerts actually get delivered.
class CommunicationChannel {
public:
    virtual ~CommunicationChannel() {}
    virtual void sendAlert(const std::string& message, const std::string& location) = 0;
};

#endif
