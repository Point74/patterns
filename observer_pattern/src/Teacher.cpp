#include "Teacher.h"

using namespace std;

void Teacher::submitReport() {
    hasReport = true;
}

void Teacher::checkReport(const string& nameTeacher) {
    if (!hasReport) {
        cout << nameTeacher << " don't submit report!\n";
        notify();
    }
}

void Teacher::notify() {
    for (auto observer : observers) {
        if (observer) {
            observer->update();
        }
    }
}

void Teacher::attach(Observer* observer) {
    observers.push_back(observer);
}

void Teacher::detach(Observer* obs) {
    observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
}

string Teacher::getName() const {
    return name;
}
