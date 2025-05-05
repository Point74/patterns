#pragma once

#include <utility>
#include <set>
#include <iomanip>
#include <iostream>

class Field {
    static const int sizeField = 20;
    std::set<std::pair<int, int>> occupiedCells; // занятие позиции на карте
    char FIELD[sizeField][sizeField]{};

public:
    Field();

    void createField();

    void printField() const;

    bool isOutside(const std::pair<int, int>& position);

    static int getSize() ;

    bool isOccupiedCells(std::pair<int, int>& newCells);

    void setOccupiedCells(std::pair<int, int>& newCells);

    void addHero(const std::pair<int, int>& position);

    void addEnemy(const std::pair<int, int>& position);

    void removeOccupiedCells(const std::pair<int, int>& cell);

    void clearPosition(std::pair<int, int>& previousPosition);

    bool isNearEnemy(std::pair<int, int> newPosition);

    bool isNearHero(std::pair<int, int> newPosition);

    bool isCellFree(const std::pair<int, int> cell);
};