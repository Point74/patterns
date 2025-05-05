#include "enums/TypeEnemy.h"


const std::map<TypeEnemy, std::string> ENEMY_TYPE = {
        {TypeEnemy::PERSON, "Person"}
};


std::string typeEnemyToString(TypeEnemy type) {
    auto it = ENEMY_TYPE.find(type);
    if (it != ENEMY_TYPE.end()) {
        return it->second;
    }

    return "Unknown";
}