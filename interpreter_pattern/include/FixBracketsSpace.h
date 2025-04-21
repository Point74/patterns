#pragma once

#include "Expression.h"
#include <string>

class FixBracketsSpace : public Expression  {
public:
    void interpret(std::string& text) override;
};