#pragma once

#include "Expression.h"
#include <string>


class RemoveExtraSpace : public Expression {
public:
    void interpret(std::string& text) override;
};