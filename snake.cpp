#include <iostream>
#include <curses.h>
#include <unistd.h>
#include "GameBoard.hpp"
#include "Player.hpp"
#include "SpecialEvents.hpp"

int main() {
    GameBoard gameBoard(15, 15);
    Player player;
    Direction direction = Direction::LEFT;
    SpecialEvents event;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);

    event.addFood(gameBoard);
    while(!gameBoard.checkCollision()) {
        gameBoard.displayBoard();

        int key = getch();

        if(key == KEY_LEFT) {
            direction = Direction::LEFT;
        } else if(key == KEY_UP) {
            direction = Direction::UP;
        } else if(key == KEY_RIGHT) {
            direction = Direction::RIGHT;
        } else if(key == KEY_DOWN) {
            direction = Direction::DOWN;
        }

        DirectionOffset offset = player.doMove(direction);
        gameBoard.doMove(offset.widthOffset, offset.heightOffset);

        usleep(250000);
    }

    printw("works well\n");
   endwin();

    return 0;
}