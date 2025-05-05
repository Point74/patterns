#pragma once

#include <string>
#include <map>
#include <iostream>

#include "observers/Observer.h"
#include "utils/EventData.h"


class GameLogger : public Observer {
    std::map<std::string, int> characterHealth;
    std::map<std::string, int> characterArmor;
    std::map<std::string, std::pair<int, int>> characterPositions;

    void printCharacterInfo(const std::string& name);

public:
    void update(const EventData& data) override;

    void registerCharacter(const std::string& name, int health, int armor, const std::pair<int, int>& position);

    void updateCharacterStats(const std::string& name, int health, int armor);

};