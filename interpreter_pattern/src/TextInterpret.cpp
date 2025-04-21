#include "TextInterpret.h"

using namespace std;

void TextInterpret::addExpressions(const shared_ptr<Expression>& expression) {
    expressions.push_back(expression);
}

void TextInterpret::interpret(string& text) {
    for (const auto& expression : expressions) {
        expression->interpret(text);
    }
}