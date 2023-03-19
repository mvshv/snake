#include <iostream>
#include <unistd.h>
#include "GameBoard.hpp"
#include "Player.hpp"
#include "SpecialEvents.hpp"


int main() {

    GameBoard gameBoard(10, 10);
    gameBoard.displayBoard();

    gameBoard.doMove(0, 1);
    sleep(1);
    gameBoard.displayBoard();


    return 0;
}