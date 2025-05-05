#pragma once

#include "core/Character.h"
#include "enums/Direction.h"
#include "observers/GameLogger.h"

#include <string>
#include <memory>
#include <utility>
#include <iostream>


class Hero : public Character {
    Hero(const std::string& _name, int _health, int _armor, int _damage, std::pair<int, int> _position);

    static std::unique_ptr<Hero> instance;

public:
    Hero(const Hero&) = delete;
    Hero& operator=(const Hero&) = delete;

    static Hero* getInstance(const std::string& name = "", int health = 100, int armor = 100, int damage = 100, std::pair<int, int> position = {0, 0});

    static void resetInstance();

    std::string getName() const override;

    int getHealth() const override;

    int getArmor() const override;

    void receiveDamage(const int& incomingDamage) override;

    void attack(Character& target) override;

    bool isAlive() override;

    void setPosition(const int& x, const int& y) override;

    std::pair<int, int> getPosition() override;

    int getDamage() const override;

    void move(Direction direction);

    void printInfo() override;
};