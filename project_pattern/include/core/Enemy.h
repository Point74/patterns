#pragma once

#include "core/Character.h"
#include "enums/TypeEnemy.h"
#include "observers/GameLogger.h"

#include <string>
#include <utility>
#include <functional>


class Enemy : public Character {
    TypeEnemy typeEnemy;

public:
    Enemy(const int& id, int _health, int _armor, int _damage, std::pair<int, int> _position, TypeEnemy typeEnemy);

    std::string getName() const override;

    int getHealth() const override;

    int getArmor() const override;

    void receiveDamage(const int& incomingDamage) override;

    void attack(Character& target) override;

    bool isAlive() override;

    void setPosition(const int& x, const int& y) override;

    std::pair<int, int> getPosition() override;

    int getDamage() const override;

    void moveOrAttack(Character& hero,
                      const std::function<bool(const std::pair<int, int>&)>& isCellEmpty,
                      const std::function<bool(const std::pair<int, int>&)>& isHeroNear,
            const std::function<void(std::pair<int, int>&, const std::pair<int, int>&)>& updateEnemyPosition);

    void printInfo() override;
};
