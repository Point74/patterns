#pragma once

#include "Expression.h"
#include <string>
#include <memory>
#include <vector>


class TextInterpret {
    std::vector<std::shared_ptr<Expression>> expressions;

public:
    void addExpressions(const std::shared_ptr<Expression>& expression);

    void interpret(std::string& text);
};