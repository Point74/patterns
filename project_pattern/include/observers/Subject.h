#pragma once

#include "observers/Observer.h"
#include "utils/EventData.h"

#include <list>


class Subject {
private:
    std::list<Observer*> observers;

public:
    virtual ~Subject() = default;

    void attach(Observer* observer);

    void detach(Observer* observer);

    void notify(const EventData& data);

    std::list<Observer*>& getObservers();
};