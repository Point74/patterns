#include "ReplaceHyphenWithDash.h"

using namespace std;


void ReplaceHyphenWithDash::interpret(string& text) {
    string result = {};

    for (int i = 0; i < text.size(); ++i) {
        if (i == 0) {
            if (text[i] == '-' && i + 1 < text.size() && text[i + 1] == ' ') {
                result += "—";
                continue;
            }

        }

        else {
            if (text[i - 1] == ' ' && text[i] == '-' && i + 1 < text.size() && text[i + 1] == ' ') {
                result += "—";
                continue;
            }
        }

        result += text[i];
    }

    text = result;
}

