#include "observers/Subject.h"


void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    observers.remove(observer);
}

void Subject::notify(const EventData& data) {
    for (auto& observer : observers) {
        observer->update(data);
    }
}

std::list<Observer*>& Subject::getObservers() {
    return observers;
}
