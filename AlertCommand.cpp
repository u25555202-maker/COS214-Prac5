#include "AlertCommand.h"
#include "CommunicationChannel.h"

AlertCommand::AlertCommand(CommunicationChannel* channel, std::string message, std::string location)
    : channel(channel), message(std::move(message)), location(std::move(location)) {}

void AlertCommand::execute() {
    channel->sendAlert(message, location);
}

std::string AlertCommand::description() const {
    return "Alert: " + message;
}
