#include "Expression.h"
#include "TextInterpret.h"
#include "RemoveExtraSpace.h" // ������� ������ �������
#include "ReplaceHyphenWithDash.h" // ������ ������ �� ����
#include "ReplaceQuotes.h" // ������ �������  � � �> � �
#include "FixBracketsSpace.h" // ������ ������ ������� � ������� ������� � �� ����� � �������
#include "RemoveExtraNewLines.h" // ������ ������ ����� ������

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