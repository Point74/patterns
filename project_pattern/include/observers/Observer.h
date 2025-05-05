#pragma once

#include "utils/EventData.h"


class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const EventData& data) = 0;

};