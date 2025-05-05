#pragma once

#include <string>
#include <utility>
#include "observers/Subject.h"


class Character : public Subject {
protected:
    std::string name;
    int health;
    int armor;
    int damage;
    std::pair<int, int> position;

public:
    Character(std::string _name, int _health, int _armor, int _damage, std::pair<int, int> _position)
            : name(std::move(_name)), health(_health), armor(_armor), damage(_damage), position(std::move(_position)) {}

    virtual ~Character() = default;


    virtual std::string getName() const = 0;

    virtual int getHealth() const = 0;

    virtual int getArmor() const = 0;

    virtual void receiveDamage(const int& incomingDamage) = 0;
    virtual bool isAlive() = 0;
    virtual void setPosition(const int& x, const int& y) = 0;
    virtual std::pair<int, int> getPosition() = 0;
    virtual int getDamage() const = 0;
    virtual void attack(Character& target) = 0;
    virtual void printInfo() = 0;
};