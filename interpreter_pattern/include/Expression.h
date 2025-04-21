#pragma once

#include <string>


class Expression {
public:
    virtual void interpret(std::string& text) = 0;
    virtual ~Expression() = default;
};