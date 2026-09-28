#ifndef LEGACYPAGERADAPTER_H
#define LEGACYPAGERADAPTER_H

#include "CommunicationChannel.h"
#include "LegacyPagerSystem.h"
#include <memory>
#include <string>

// Object Adapter (GoF Adapter pattern). Translates between the interface
// CampusGuard wants (CommunicationChannel::sendAlert(message, location))
// and the incompatible legacy interface
// (LegacyPagerSystem::broadcastPage(code, zoneId, payload)). This is a real
// translation, not a pass-through wrapper: the free-text message is mapped
// to a numeric priority code and the human-readable location is mapped to
// a zone identifier.
//
// Ownership: the adapter OWNS the legacy system it wraps (unique_ptr) --
// nothing else in CampusGuard should reach past the adapter to talk to the
// legacy system directly.
class LegacyPagerAdapter : public CommunicationChannel {
public:
    explicit LegacyPagerAdapter(std::unique_ptr<LegacyPagerSystem> legacySystem);
    void sendAlert(const std::string& message, const std::string& location) override;

private:
    std::unique_ptr<LegacyPagerSystem> legacySystem;
    int mapToPriorityCode(const std::string& message) const;
    std::string mapToZoneId(const std::string& location) const;
};

#endif
