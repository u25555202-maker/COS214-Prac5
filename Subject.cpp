#include "Subject.h"
#include <algorithm>
using namespace std;

void Subject::attach(Observer* obs) {
    observers.push_back(obs);
}

void Subject::detach(Observer* obs) {
    observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
}

void Subject::notify() {
    for (Observer* obs : observers) {
        obs->update(this);
    }
}
