#include "utils.h"

Objects createAllObjects() {
    Objects objects;

    for (int i = 0; i < 3; ++i) {
        objects.teachers.push_back(new Teacher("Teacher_" + std::to_string(i + 1)));
    }

    return objects;
}

void createLink(std::vector<Teacher*>& teachers, Deanery& deanery) {
    for (auto& teacher : teachers) {
        teacher->attach(&deanery);
    }
}