#include "observers/GameStatistics.h"


void GameStatistics::update(const EventData& data) {
    switch (data.eventType) {
        case GameEvent::CHARACTER_ATTACKED:
            if (data.characterName.find("Enemy") == std::string::npos) {
                totalDamageDealt += data.value;
            }
            break;

        case GameEvent::CHARACTER_DAMAGED:
            if (data.characterName.find("Enemy") == std::string::npos) {
                totalDamageReceived += data.value;
            }
            break;

        case GameEvent::CHARACTER_DIED:
            if (data.characterName.find("Enemy") != std::string::npos) {
                enemiesKilled++;
            }
            break;

        case GameEvent::GAME_OVER:
        case GameEvent::GAME_WON:
            printStatistic();
            break;
    }
}

void GameStatistics::printStatistic() {
    std::cout << "\n====== GAME STATISTICS ======" << std::endl;
    std::cout << "Total damage dealt: " << totalDamageDealt << std::endl;
    std::cout << "Total damage received: " << totalDamageReceived << std::endl;
    std::cout << "Enemies killed: " << enemiesKilled << std::endl;
    std::cout << "=============================" << std::endl;
}
