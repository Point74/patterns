#include "core/Enemy.h"


Enemy::Enemy(const int& id, int _health, int _armor, int _damage, std::pair<int, int> _position, TypeEnemy typeEnemy)
        : Character("Enemy_" + std::to_string(id), _health, _armor, _damage, _position), typeEnemy(typeEnemy) {}


std::string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}

int Enemy::getArmor() const {
    return armor;
}

void Enemy::receiveDamage(const int& incomingDamage) {
    int actualDamage;

    if (armor > 0) {
        if (incomingDamage <= armor) {
            armor -= incomingDamage;
            actualDamage = incomingDamage;

        } else {
            int remainingDamage = incomingDamage - armor;
            actualDamage = incomingDamage;
            armor = 0;
            health -= remainingDamage;
        }

    } else {
        health -= incomingDamage;
        actualDamage = incomingDamage;
    }

    if (health < 0) health = 0;

    for (auto* observer : getObservers()) {
        if (auto* logger = dynamic_cast<GameLogger*>(observer)) {
            logger->updateCharacterStats(name, health, armor);
        }
    }

    notify(EventData(GameEvent::CHARACTER_DAMAGED, name, actualDamage, position));

    if (!isAlive()) {
        for (auto* observer : getObservers()) {
            if (auto* logger = dynamic_cast<GameLogger*>(observer)) {
                logger->updateCharacterStats(name, health, armor);
            }
        }

        notify(EventData(GameEvent::CHARACTER_DIED, name, 0, position));
    }

}

void Enemy::attack(Character& target) {
    notify(EventData(GameEvent::CHARACTER_ATTACKED, name, damage, position));
    target.receiveDamage(this->getDamage());
}

bool Enemy::isAlive() {
    if (health == 0)
        return false;

    return true;
}

void Enemy::setPosition(const int& x, const int& y) {
    position.first = x;
    position.second = y;
}

std::pair<int, int> Enemy::getPosition() {
    return {position.first, position.second};
}

int Enemy::getDamage() const {
    return damage;
}

void Enemy::moveOrAttack(Character& hero,
                  const std::function<bool(const std::pair<int, int>&)>& isCellEmpty,
                  const std::function<bool(const std::pair<int, int>&)>& isHeroNear,
        const std::function<void(std::pair<int, int>&, const std::pair<int, int>&)>& updateEnemyPosition) {

    std::pair<int, int> currentPosition = getPosition();
    std::pair<int, int> newPosition = currentPosition;

    if (hero.getPosition().first < currentPosition.first)
        newPosition.first--;

    else if (hero.getPosition().first > currentPosition.first)
        newPosition.first++;

    else if (hero.getPosition().second < currentPosition.second)
        newPosition.second--;

    else if (hero.getPosition().second > currentPosition.second)
        newPosition.second++;


    if (isHeroNear(newPosition)) {
        this->attack(hero);
        return;
    }

    if (isCellEmpty(newPosition)) {
        updateEnemyPosition(position, newPosition);
        this->setPosition(newPosition.first, newPosition.second);

        notify(EventData(GameEvent::CHARACTER_MOVE, name, 0, position));

        return;
    }
}

void Enemy::printInfo() {
    std::cout << name <<
         "\nHealth: " << health <<
         "\nArmor: " << armor <<
         "\nDamage: " << damage <<
         "\nType: " << typeEnemyToString(typeEnemy) << std::endl;
}
