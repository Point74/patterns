#include "Expression.h"
#include "TextInterpret.h"
#include "RemoveExtraSpace.h" // удалить лишние пробелы
#include "ReplaceHyphenWithDash.h" // замена дефиса на тире
#include "ReplaceQuotes.h" // замена кавычек  У Ф Ч> Ђ ї
#include "FixBracketsSpace.h" // убрать лишние пробелы в круглых скобках и до точки и зап€той
#include "RemoveExtraNewLines.h" // убрать лишние новые строки

#include "utils.h"


using namespace std;


int main() {
    TextInterpret textInterpret;
    fillInterpreter(textInterpret);

    string text = loadData();

    if (text.empty()) {
        return 1;
    }

    textInterpret.interpret(text);

    saveClearText(text);
}