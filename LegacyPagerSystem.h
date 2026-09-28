#ifndef LEGACYPAGERSYSTEM_H
#define LEGACYPAGERSYSTEM_H

#include <string>

// Adaptee (GoF Adapter pattern). Represents a pre-existing, externally
// managed campus paging system CampusGuard cannot modify. Its interface is
// genuinely incompatible with CommunicationChannel: numeric priority codes
// instead of free-text severity, a "zoneId" instead of a location string,
// and a different method name/signature entirely.
class LegacyPagerSystem {
public:
    ~LegacyPagerSystem() {}
    // priorityCode: 1 = info, 2 = warning, 3 = critical (legacy convention)
    void broadcastPage(int priorityCode, const std::string& zoneId, const std::string& payload);
};

#endif
