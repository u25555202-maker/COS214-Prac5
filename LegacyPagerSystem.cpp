#include "LegacyPagerSystem.h"
#include <iostream>
using namespace std;

void LegacyPagerSystem::broadcastPage(int priorityCode, const string& zoneId, const string& payload) {
    cout << "[LEGACY-PAGER] code=" << priorityCode
         << " zone=" << zoneId
         << " payload=\"" << payload << "\"" << endl;
}
