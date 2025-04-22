#include "Deanery.h"
#include <iostream>

using namespace std;

void Deanery::update() {
    cout << "The deanery has been notified!\n";
    department->message();
}