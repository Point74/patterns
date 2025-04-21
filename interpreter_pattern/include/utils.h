#pragma once

#include "TextInterpret.h"
#include "RemoveExtraSpace.h"
#include "RemoveExtraNewLines.h"
#include "ReplaceHyphenWithDash.h"
#include "ReplaceQuotes.h"
#include "FixBracketsSpace.h"

#include <string>


void fillInterpreter(TextInterpret& textInterpret);
std::string getFullPathToFile(const std::string& relativePath);
std::string loadData();
void saveClearText(const std::string& text);