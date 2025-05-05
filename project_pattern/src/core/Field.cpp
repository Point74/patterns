#include "core/Field.h"


Field::Field() {
    createField();
}

void Field::createField() {
    for (int i = 0; i < sizeField; ++i) {
        for (int j = 0; j < sizeField; ++j) {
            FIELD[i][j] = '.';
        }
    }
}

void Field::printField() const {
    char letter = 65; // A
    std::cout << "  ";
    // setw(2) = один пробел
    for (int i = 0; i < sizeField; ++i) {
        std::cout << letter << std::setw(2);
        letter++;
    }

    std::cout << '\n';

    for (int i = 0; i < sizeField; ++i) {
        std::cout << std::setw(2) << i + 1;
        for (int j = 0; j < sizeField; ++j) {
            std::cout << std::setw(2);
            if (FIELD[i][j] == 'H') {
                std::cout << 'H';

            } else if (FIELD[i][j] == 'E') {
                std::cout << 'E';

            } else {
                std::cout << '.';
            }
        }

        std::cout << "|\n";
    }

    std::cout << "   ";
    for (int k = 0; k < sizeField; ++k) {
        std::cout << "--";
    }
}

bool Field::isOutside(const std::pair<int, int>& position) {
    return (position.first < 0 || position.first >= sizeField ||
            position.second < 0 || position.second >= sizeField);
}

int Field::getSize() {
    return sizeField;
}

bool Field::isOccupiedCells(std::pair<int, int>& newCells) {
    if (occupiedCells.find(newCells) == occupiedCells.end()) {
        return false;
    }

    return true;
}

void Field::setOccupiedCells(std::pair<int, int>& newCells) {
    occupiedCells.insert(newCells);
}

void Field::addHero(const std::pair<int, int>& position) {
    FIELD[position.first][position.second] = 'H';
}

void Field::addEnemy(const std::pair<int, int>& position) {
    FIELD[position.first][position.second] = 'E';
}

void Field::removeOccupiedCells(const std::pair<int, int>& cell) {
    occupiedCells.erase(cell);
}

void Field::clearPosition(std::pair<int, int>& previousPosition) {
    FIELD[previousPosition.first][previousPosition.second] = '.';
    removeOccupiedCells(previousPosition);
}

bool Field::isNearEnemy(std::pair<int, int> newPosition) {
    if (FIELD[newPosition.first][newPosition.second] == 'E')
        return true;

    return false;
}

bool Field::isNearHero(std::pair<int, int> newPosition) {
    if (FIELD[newPosition.first][newPosition.second] == 'H')
        return true;

    return false;
}

bool Field::isCellFree(const std::pair<int, int> cell) {
    return FIELD[cell.first][cell.second] == '.';
}
