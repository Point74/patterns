#pragma once

#include "Expression.h"
#include <string>


class RemoveExtraNewLines : public Expression {
public:
    void interpret(std::string& text) override;
};