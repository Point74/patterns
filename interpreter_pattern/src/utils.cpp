#include "utils.h"

#include <iostream>
#include <fstream>
#include <filesystem>


using namespace std;
namespace fs = std::filesystem;


void fillInterpreter(TextInterpret& textInterpret) {
    textInterpret.addExpressions(make_shared<RemoveExtraSpace>());
    textInterpret.addExpressions(make_shared<ReplaceHyphenWithDash>());
    textInterpret.addExpressions(make_shared<ReplaceQuotes>());
    textInterpret.addExpressions(make_shared<FixBracketsSpace>());
    textInterpret.addExpressions(make_shared<RemoveExtraNewLines>());
}


string getFullPathToFile(const string& relativePath) {
    fs::path exePath = fs::current_path();
    fs::path fullPath = exePath / "../" / relativePath;

    return fullPath.lexically_normal().string();
}


string loadData() {
    string filePath = "data/file.txt";

    filePath = getFullPathToFile(filePath);

    fstream fileIn(filePath, ios::in);

    if (!fileIn.is_open()) {
        cerr << "File don't open!";
        return {};
    }

    string text {(istreambuf_iterator<char>(fileIn)), istreambuf_iterator<char>()};

    fileIn.close();

    return text;
}


void saveClearText(const string& text) {
    string filePath = "data/clearFile.txt";

    filePath = getFullPathToFile(filePath);

    fstream fileOut(filePath, ios::out);

    if (!fileOut.is_open()) {
        cerr << "File don't open!";
        return;
    }

    fileOut << text;
    fileOut.close();
}