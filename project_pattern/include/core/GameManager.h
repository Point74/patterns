#pragma once

#include "core/Enemy.h"
#include "core/Hero.h"
#include "core/Field.h"
#include "observers/GameStatistics.h"
#include "factory/EnemyFactory.h"
#include "utils/Random.h"

#include <vector>
#include <memory>
#include <utility>



class GameManager {
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::unique_ptr<Field> field;
    Hero* hero;
    GameLogger logger;
    GameStatistics statistics;

public:
    GameManager();

    void printAllCharactersInfo();

    void createHero();

    void createEnemies(const int& count);

    void fillFieldCharacters();

    bool isAliveEnemies();

    Enemy* getNearlyEnemy(const std::pair<int, int>& position);

    void deleteEnemy(Enemy* enemyToRemove);

    bool moveOrAttack(std::pair<int, int>&& position, Direction direction, std::pair<int, int>& previousPosition);

    void startGame(const int& quantityEnemies);

    void physicGame();
};

