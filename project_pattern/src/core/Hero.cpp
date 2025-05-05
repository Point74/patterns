#include "core/Hero.h"


std::unique_ptr<Hero> Hero::instance = nullptr;

Hero::Hero(const std::string& _name, int _health, int _armor, int _damage, std::pair<int, int> _position)
        : Character(_name, _health, _armor, _damage, _position) {}

Hero* Hero::getInstance(const std::string& name, int health, int armor, int damage, std::pair<int, int> position) {
    if (!instance) {
        instance = std::unique_ptr<Hero>(new Hero(name, health, armor, damage, position));
    }

    return instance.get();
}

void Hero::resetInstance() {
    instance.reset();
}

std::string Hero::getName() const {
    return name;
}

int Hero::getHealth() const {
    return health;
}

int Hero::getArmor() const {
    return armor;
}

void Hero::receiveDamage(const int& incomingDamage) {
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
        notify(EventData(GameEvent::GAME_OVER, name, 0, position));
    }
}

void Hero::attack(Character& target) {
    notify(EventData(GameEvent::CHARACTER_ATTACKED, name, damage, position));
    target.receiveDamage(this->getDamage());
}

bool Hero::isAlive() {
    if (health == 0)
        return false;

    return true;
}

void Hero::setPosition(const int& x, const int& y) {
    position.first = x;
    position.second = y;
}

std::pair<int, int> Hero::getPosition() {
    return {position.first, position.second};
}

int Hero::getDamage() const {
    return damage;
}

void Hero::move(Direction direction) {
    switch (direction) {
        case Direction::UP: {
            position.first--;
            break;
        }

        case Direction::DOWN:
            position.first++;
            break;

        case Direction::LEFT:
            position.second--;
            break;

        case Direction::RIGHT:
            position.second++;
            break;
    }

    notify(EventData(GameEvent::CHARACTER_MOVE, name, 0, position));

    for (auto* observer : getObservers()) {
        if (auto* logger = dynamic_cast<GameLogger*>(observer)) {
            logger->updateCharacterStats(name, health, armor);
        }
    }
}

void Hero::printInfo() {
    std::cout << "\nHero:" <<
         "\nName: " << name <<
         "\nHealth: " << health <<
         "\nArmor: " << armor <<
         "\nDamage: " << damage << std::endl;
}
