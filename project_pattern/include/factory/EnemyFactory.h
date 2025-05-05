#pragma once

#include "factory/FactoryCharacter.h"
#include "utils/Random.h"
#include "enums/TypeEnemy.h"
#include "core/Enemy.h"

#include <memory>


class EnemyFactory : public FactoryCharacter {
    int currentID = 1;

public:
    std::unique_ptr<Character> createCharacter() override;
};