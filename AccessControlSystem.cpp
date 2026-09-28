#include "AccessControlSystem.h"
#include <iostream>
using namespace std;

void AccessControlSystem::lockArea(const string& area) {
    cout << "[ACCESS-CONTROL] Locking area: " << area << endl;
}

void AccessControlSystem::unlockArea(const string& area) {
    cout << "[ACCESS-CONTROL] Unlocking area: " << area << endl;
}

void AccessControlSystem::restrictArea(const string& area) {
    cout << "[ACCESS-CONTROL] Restricting access to area: " << area << endl;
}
