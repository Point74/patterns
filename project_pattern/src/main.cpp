#include "core/GameManager.h"


int main() {
    GameManager game;
    game.startGame(5); // enter qunatity enemies, if you want another number

    Hero::resetInstance();
}