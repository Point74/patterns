#pragma once

#include <string>
#include <utility>

#include "enums/GameEvent.h"


struct EventData {
    GameEvent eventType;
    std::string characterName;
    int value; // damage, health etc.
    std::pair<int, int> position;

    EventData(GameEvent type, std::string name, int val = 0,  std::pair<int, int> pos = {0, 0})
            : eventType(type), characterName(std::move(name)), value(val), position(std::move(pos)) {}
};