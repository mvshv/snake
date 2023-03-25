#include "GameBoard.hpp"
#include "SpecialEvents.hpp"
#include <ncurses.h>

GameBoard::GameBoard(int height, int width, Player& player) :
  HEIGHT(height),
  WIDTH(width),
  player(player),
  board(height, std::vector<int>(width, static_cast<int>(Objects::EMPTY))) {

    for(int i = 0; i < HEIGHT; ++i) {
      for(int j = 0; j < WIDTH; ++j) {
        if(i == 0 || i == HEIGHT - 1)
          board[i][j] = static_cast<int>(Objects::WALL);
        if(j == 0 || j == WIDTH - 1)
          board[i][j] = static_cast<int>(Objects::WALL);
      }
    }
    board[height / 2][width / 2] = static_cast<int>(Objects::SNAKE_HEAD);

    newRow = height / 2;
    newCol = width / 2;
    snakeLength = 0;
  }

#include <ncurses.h>

void GameBoard::displayBoard() const {

  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      switch (board[i][j]) {
        case static_cast<int>(Objects::EMPTY):
          mvprintw(i, j * 2, "  ");
          break;
        case static_cast<int>(Objects::WALL):
          mvprintw(i, j * 2, "##");
          break;
        case static_cast<int>(Objects::FOOD):
          mvprintw(i, j * 2, "%%");
          break;
        case static_cast<int>(Objects::SNAKE_HEAD):
          mvprintw(i, j * 2, "[]");
          break;
        case static_cast<int>(Objects::SNAKE_BODY):
          mvprintw(i, j * 2, "{}");
          break;
      }
    }
  }

  refresh();
}


int GameBoard::doMove(int heightOffset, int widthOffset) {
    HeadLocation headLocation = findLocationOfHead();
    BodyLocation bodyLocation(headLocation);

    bodyLocations.push_back(headLocation);

    if (bodyLocations.size() > player.getNumberOfBodyParts()) {
        board[bodyLocations[0].ROW][bodyLocations[0].COL] = static_cast<int>(Objects::EMPTY);
        bodyLocations.erase(bodyLocations.begin());
    }
  
    newCol = headLocation.COL + heightOffset;
    newRow = headLocation.ROW + widthOffset;

    for(int i = 0; i < bodyLocations.size(); ++i) {
        board[bodyLocations[i].ROW][bodyLocations[i].COL] = static_cast<int>(Objects::SNAKE_BODY);
    }

    if (board[newRow][newCol] == static_cast<int>(Objects::FOOD)) {
        printw("ate the food\n");
        player.updatePoints(5);
        specialEvents->addFood(*this);
    } else if (board[newRow][newCol] == static_cast<int>(Objects::SNAKE_BODY)) {
        printw("hit the body\n");
        return checkCollision();
    } else if (board[newRow][newCol] == static_cast<int>(Objects::WALL)) {
        printw("hit the wall\n");
        return checkCollision();
    }
    board[newRow][newCol] = static_cast<int>(Objects::SNAKE_HEAD);

    return checkCollision();
}

HeadLocation GameBoard::findLocationOfHead() {
  HeadLocation headLocation;

    for(int i = 0; i < HEIGHT; ++i) {
    for(int j = 0; j < WIDTH; ++j) {
      if(board[i][j] == static_cast<int>(Objects::SNAKE_HEAD)) {
        headLocation.ROW = i;
        headLocation.COL = j;
        break;
      }
    }
  }
  return headLocation;
}



bool GameBoard::checkCollision() {

    if (board[newRow][newCol] == static_cast<int>(Objects::WALL)) {
        printw("hit the wall\n");
        return true;
    }

    if (newRow < 0 || newRow >= HEIGHT || newCol < 0 || newCol >= WIDTH) {
        printw("out of bounds\n");
        return true;
    }

    if (board[newRow][newCol] == static_cast<int>(Objects::SNAKE_BODY)) {
        printw("hit the body\n");
        return true;
    }

    return false;
}

void GameBoard::setSpecialObjectAt(int height, int width, Objects) {
  board[height][width] = static_cast<int>(Objects::FOOD);
  FoodLocation foodLocation;
  foodLocation.ROW = height;
  foodLocation.COL = width;
}
