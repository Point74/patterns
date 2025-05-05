#pragma once

#include "Observer.h"
#include "Subject.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>


class Teacher : public Subject {
    std::string name;
    std::vector<Observer*> observers;
    bool hasReport = false;

public:
    explicit Teacher(std::string _name) : name(std::move(_name)) {}

    void submitReport();

    void checkReport(const std::string& nameTeacher);

    void notify() override;

    void attach(Observer* observer) override;

    void detach(Observer* observer) override;

    std::string getName() const;
};