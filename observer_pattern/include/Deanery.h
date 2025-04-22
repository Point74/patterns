#pragma once

#include "Observer.h"
#include "Department.h"


class Deanery : public Observer {
    Department* department;
public:
    explicit Deanery(Department* depart) : department(depart) {}
    void update() override;
};