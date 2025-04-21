#include "ReplaceQuotes.h"

using namespace std;

void ReplaceQuotes::interpret(string& text) {
    string result = {};
    int count = 0;

    for (char element : text) {
        if (element != '"') {
            result += element;

        } else {
            if (count == 0) {
                result += "«";
                count++;

            } else {
                result += "»";
                count = 0;
            }
        }
    }

    text = result;
}
