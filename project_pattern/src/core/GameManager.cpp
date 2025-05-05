#include "core/GameManager.h"


GameManager::GameManager() {
    field = std::make_unique<Field>();
    hero = nullptr;
}

void GameManager::printAllCharactersInfo() {
    hero->printInfo();

    for (const auto& enemy : enemies) {
        enemy->printInfo();
    }
}

void GameManager::createHero() {
    std::string name;
    int health, armor, damage;

    std::cout << "Enter name: ";
    getline(std::cin, name);

    std::cout << "Enter health: ";
    std::cin >> health;

    std::cout << "Enter armor: ";
    std::cin >> armor;

    std::cout << "Enter damage: ";
    std::cin >> damage;

    std::pair<int, int> position = {randomOut(0, 19), randomOut(0, 19)};
    hero = Hero::getInstance(name, health, armor, damage, position);

    hero->attach(&logger);
    hero->attach(&statistics);

    logger.registerCharacter(hero->getName(), hero->getHealth(), hero->getArmor(), position);

}

void GameManager::createEnemies(const int& count) {
    EnemyFactory factoryEnemies;

    for (int i = 0; i < count; ++i) {
        auto enemy = dynamic_cast<Enemy*>(factoryEnemies.createCharacter().release());
        if (enemy) {
            enemy->attach(&logger);
            enemy->attach(&statistics);

            std::pair<int, int> position = enemy->getPosition();
            logger.registerCharacter(enemy->getName(), enemy->getHealth(), enemy->getArmor(), position);


            enemies.push_back(std::unique_ptr<Enemy>(enemy));
        }
    }
}

void GameManager::fillFieldCharacters() {
    std::pair<int, int> newCell;

    hero->setPosition(randomOut(0, field->getSize() - 1), randomOut(0, field->getSize() - 1));
    newCell = hero->getPosition();

    field->setOccupiedCells(newCell);
    field->addHero(hero->getPosition());

    for (auto& enemy : enemies) {
        while (true) {
            enemy->setPosition(randomOut(0, field->getSize() - 1), randomOut(0, field->getSize() - 1));
            newCell = enemy->getPosition();


            if (field->isOccupiedCells(newCell)) {
                continue;
            }

            field->setOccupiedCells(newCell);

            break;
        }

        field->addEnemy(enemy->getPosition());
    }
}

bool GameManager::isAliveEnemies() {
    size_t aliveEnemy = enemies.size();

    for (auto& enemy : enemies) {
        if (!enemy->isAlive()) {
            aliveEnemy--;
        }
    }

    if (aliveEnemy == 0) {
        return false;
    }

    return true;
}

Enemy* GameManager::getNearlyEnemy(const std::pair<int, int>& position) {
    for (auto& enemy : enemies) {
        if (enemy->getPosition() == position && enemy->isAlive()) {
            return enemy.get();
        }
    }

    return nullptr;
}

void GameManager::deleteEnemy(Enemy* enemyToRemove) {
    auto it = remove_if(enemies.begin(), enemies.end(),
                        [enemyToRemove](const std::unique_ptr<Enemy>& enemy) {
                            return enemy.get() == enemyToRemove;
                        });

    if (it != enemies.end()) {
        enemies.erase(it);
    }
}

bool GameManager::moveOrAttack(std::pair<int, int>&& position, Direction direction, std::pair<int, int>& previousPosition) { // действие героя
    if (field->isOutside(position)) {
        return false;
    }

    if (field->isNearEnemy(position)) {
        Enemy* enemy = getNearlyEnemy(position);
        if (enemy != nullptr) {
            hero->attack(*enemy);

            if (!enemy->isAlive()) {
                field->clearPosition(position);
                deleteEnemy(enemy);
            }
        }

        return true;
    }

    hero->move(direction);
    field->clearPosition(previousPosition);
    field->addHero(hero->getPosition());

    return true;
}

void GameManager::startGame(const int& quantityEnemies) {
    createHero();
    createEnemies(quantityEnemies);
    fillFieldCharacters();
    printAllCharactersInfo();
    physicGame();
}

void GameManager::physicGame() {
    while (hero->isAlive() && isAliveEnemies()) {
        field->printField();

        char command;
        std::cout << "\nEnter command for moveOrAttack (w/a/s/d): ";
        std::cin >> command;

        std::pair<int, int> previousPosition = hero->getPosition();

        switch (toupper(command)) {
            case 'W': {
                moveOrAttack({previousPosition.first - 1, previousPosition.second}, Direction::UP, previousPosition);
                break;
            }

            case 'A': {
                moveOrAttack({previousPosition.first, previousPosition.second - 1}, Direction::LEFT,previousPosition);
                break;
            }

            case 'S': {
                moveOrAttack({previousPosition.first + 1, previousPosition.second}, Direction::DOWN,previousPosition);
                break;
            }

            case 'D': {
                moveOrAttack({previousPosition.first, previousPosition.second + 1}, Direction::RIGHT,previousPosition);
                break;
            }

            default: {
                std::cout << "Invalid command!\n";
                break;
            }
        }

        std::cout << '\n';

        for (auto& enemy : enemies) {
            enemy->moveOrAttack(
                    *hero,
                    [this](const std::pair<int, int> &pos) {
                        return field->isCellFree(pos);
                    },
                    [this](const std::pair<int, int> &newPos) {
                        return field->isNearHero(newPos);
                    },
                    [this](std::pair<int, int> &from, const std::pair<int, int> &to) {
                        field->clearPosition(from);
                        field->addEnemy(to);
                    }
            );

            if (!hero->isAlive()) {
                break;
            }
        }
    }

    if (!hero->isAlive())
        std::cout << "\nGame over! Hero is dead!\n";
    else {
        if (hero) {
            hero->notify(EventData(GameEvent::GAME_WON, hero->getName()));
        }
    }
}

