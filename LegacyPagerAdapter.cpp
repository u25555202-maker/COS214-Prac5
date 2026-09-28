#include "LegacyPagerAdapter.h"
#include <algorithm>
using namespace std;

LegacyPagerAdapter::LegacyPagerAdapter(unique_ptr<LegacyPagerSystem> legacySystem)
    : legacySystem(std::move(legacySystem)) {}

void LegacyPagerAdapter::sendAlert(const string& message, const string& location) {
    int code = mapToPriorityCode(message);
    string zone = mapToZoneId(location);
    legacySystem->broadcastPage(code, zone, message);
}

int LegacyPagerAdapter::mapToPriorityCode(const string& message) const {
    string lower = message;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower.find("evacuate") != string::npos || lower.find("critical") != string::npos) {
        return 3;
    }
    if (lower.find("warning") != string::npos || lower.find("secure") != string::npos) {
        return 2;
    }
    return 1;
}

string LegacyPagerAdapter::mapToZoneId(const string& location) const {
    string zone = location;
    replace(zone.begin(), zone.end(), ' ', '-');
    transform(zone.begin(), zone.end(), zone.begin(), ::toupper);
    return "ZONE-" + zone;
}
