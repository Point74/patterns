#include "Observer.h" // наблюдатель
#include "Subject.h" // наблюдаемый
#include "Deanery.h" // деканат
#include "Teacher.h"
#include "Department.h" // кафедра
#include "utils.h"

#include <iostream>


int main() {
    Objects objects = createAllObjects();
    createLink(objects.teachers, objects.deanery);

    for (auto& teacher : objects.teachers) {
        teacher->checkReport(teacher->getName());
    }

    objects.teachers[0]->submitReport();

    std::cout << "-------------------\n";

    for (auto& teacher : objects.teachers) {
        teacher->checkReport(teacher->getName());
    }
}