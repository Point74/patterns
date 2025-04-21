#include "RemoveExtraNewLines.h"

using namespace std;


void RemoveExtraNewLines::interpret(string& text) {
    string result = {};
    bool lastWasNewLine = false;

    for (char element : text) {
        if (element != '\n') {
            result += element;
            lastWasNewLine = false;

        } else {
            if (!lastWasNewLine) {
                result += '\n';
                lastWasNewLine = true;
            }
        }
    }

    text = result;
}
