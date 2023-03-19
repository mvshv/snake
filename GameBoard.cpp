#include "GameBoard.hpp"

GameBoard::GameBoard(int height, int width) :
  HEIGHT(height),
  WIDTH(width),
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
  } 

void GameBoard::displayBoard() const {
  for(int i = 0; i < HEIGHT; ++i) {
    for(int j = 0; j < WIDTH; ++j) {
      std::cout << board[i][j] << " ";
    }
      std::cout << "\n";
  }
}

int GameBoard::doMove(int heightOffset, int widthOffset) {
  
  HeadLocation headLocation = findLocationOfHead();

  int newCol = headLocation.COL + heightOffset;
  int newRow = headLocation.ROW + widthOffset;

  board[headLocation.ROW][headLocation.COL] = static_cast<int>(Objects::EMPTY);

  board[newRow][newCol] = static_cast<int>(Objects::SNAKE_HEAD);
  if(board[newRow][newCol] == static_cast<int>(Objects::FOOD)) {
    std::cout << "ate the food \n";
  }
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
  HeadLocation headLocation = findLocationOfHead();

  if(board[headLocation.ROW][headLocation.COL] == static_cast<int>(Objects::WALL)) {
    std::cout << "hit the wall\n";
    return true;
  }

  // TODO: Check for collision with snake's body

  return false;
}