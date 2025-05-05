#include "factory/EnemyFactory.h"


std::unique_ptr<Character> EnemyFactory::createCharacter() {
    int health = randomOut(50, 150);
    int armor = randomOut(0, 50);
    int damage = randomOut(15, 30);
    std::pair<int, int> position = {randomOut(0, 19), randomOut(0, 19)};
    TypeEnemy typeEnemy = TypeEnemy::PERSON;

    auto enemy = std::make_unique<Enemy>(currentID, health, armor, damage, position, typeEnemy);
    currentID++;

    return enemy;
}
