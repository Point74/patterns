#pragma once

#include "core/Character.h"

#include <memory>


class FactoryCharacter {
public:
    virtual std::unique_ptr<Character> createCharacter() = 0;
    virtual ~FactoryCharacter() = default;
};