#include "FixBracketsSpace.h"

using namespace std;

void FixBracketsSpace::interpret(string& text) {
    string result = {};

    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            if ((i > 0 && text[i - 1] == '(') ||
                (i + 1 < text.size() && text[i + 1] == ')') ||
                (i + 1 < text.size() && text[i + 1] == ',') ||
                (i + 1 < text.size() && text[i + 1] == '.')) {

                continue;
            }
        }

        result += text[i];
    }

    text = result;
}
