#include "observers/GameLogger.h"


void GameLogger::printCharacterInfo(const std::string& name) {
    std::cout << "    Character info: " << name;

    if (characterPositions.find(name) != characterPositions.end()) {
        std::cout << " | Position: (" << characterPositions[name].first
             << ", " << characterPositions[name].second << ")";
    }

    if (characterHealth.find(name) != characterHealth.end()) {
        std::cout << " | Health: " << characterHealth[name];
    }

    if (characterArmor.find(name) != characterArmor.end()) {
        std::cout << " | Armor: " << characterArmor[name];
    }

    std::cout << std::endl;
}

void GameLogger::update(const EventData& data) {
    if (data.position.first != 0 || data.position.second != 0) {
        characterPositions[data.characterName] = data.position;
    }

    switch (data.eventType) {
        case GameEvent::CHARACTER_MOVE:
            std::cout << "[LOG] " << data.characterName << " moved to position ("
                 << data.position.first << ", " << data.position.second << ")\n";
            printCharacterInfo(data.characterName);
            break;

        case GameEvent::CHARACTER_ATTACKED:
            std::cout << "[LOG] " << data.characterName << " attacked with "
                 << data.value << " damage\n";
            printCharacterInfo(data.characterName);
            break;

        case GameEvent::CHARACTER_DAMAGED: {
            std::cout << "[LOG] " << data.characterName << " received "
                 << data.value << " damage\n";
            printCharacterInfo(data.characterName);
            break;
        }

        case GameEvent::CHARACTER_DIED:
            std::cout << "[LOG] " << data.characterName << " died!\n";
            characterHealth[data.characterName] = 0;
            printCharacterInfo(data.characterName);
            break;

        case GameEvent::GAME_OVER:
            std::cout << "[LOG] Game over! " << data.characterName << " lost!\n";
            break;

        case GameEvent::GAME_WON:
            std::cout << "[LOG] Game won! Congratulations!\n";
            break;
    }
}

void GameLogger::registerCharacter(const std::string& name, int health, int armor, const std::pair<int, int>& position) {
    characterHealth[name] = health;
    characterArmor[name] = armor;
    characterPositions[name] = position;
}

void GameLogger::updateCharacterStats(const std::string& name, int health, int armor) {
    characterHealth[name] = health;
    characterArmor[name] = armor;
}

