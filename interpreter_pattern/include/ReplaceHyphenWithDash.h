#pragma once

#include "Expression.h"
#include <string>

class ReplaceHyphenWithDash : public Expression {
public:
    void interpret(std::string& text) override;
};
