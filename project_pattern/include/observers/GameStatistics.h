#pragma once

#include "observers/Observer.h"
#include "utils/EventData.h"

#include <iostream>
#include <string>


class GameStatistics : public Observer {
    int totalDamageDealt = 0;
    int totalDamageReceived = 0;
    int enemiesKilled = 0;

public:
    void update(const EventData& data) override;

    void printStatistic();
};