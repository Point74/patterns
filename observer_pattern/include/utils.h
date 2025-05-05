#pragma once

#include "Deanery.h"
#include "Teacher.h"
#include "Department.h"
#include <vector>


struct Objects {
    Department department;
    Deanery deanery;
    std::vector<Teacher*> teachers;

    Objects() : deanery(&department) {}

    ~Objects() {
        for (auto teacher : teachers) {
            delete teacher;
        }
    }
};


Objects createAllObjects();
void createLink(std::vector<Teacher*>& teachers, Deanery& deanery);