#include "RemoveExtraSpace.h"

using namespace std;

void RemoveExtraSpace::interpret(string& text) {
    string result = {};
    bool lastWasSpace = false;

    for (char element : text) {
        if (element != ' ') {
            result += element;
            lastWasSpace = false;

        } else {
            if (!lastWasSpace) {
                result += element;
                lastWasSpace = true;
            }
        }
    }

    text = result;
}