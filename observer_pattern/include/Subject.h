#pragma once

#include "Observer.h"

class Subject {
public:
    virtual void notify() = 0;
    virtual void attach(Observer* obs) = 0; // подписать наблюдателя
    virtual void detach(Observer* obs) = 0; // отписать наблюдателя
};