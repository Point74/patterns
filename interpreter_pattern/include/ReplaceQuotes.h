#pragma once

#include "Expression.h"
#include <string>


class ReplaceQuotes : public Expression {
public:
    void interpret(std::string& text);
};