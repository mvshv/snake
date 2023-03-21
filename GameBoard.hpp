#include <iostream>
#include <string>
#include <vector>

enum class Objects : int {
    EMPTY = 0,
    SNAKE_HEAD = 1,
    SNAKE_BODY = 2,
    FOOD = 3,
    WALL = 4
};

struct HeadLocation {
    int ROW;
    int COL;
};

class GameBoard {

public:
    GameBoard(int HEIGHT, int WIDTH);
    void displayBoard() const;
    int doMove(int heightOffset, int widthOffset);
    bool checkCollision();

    HeadLocation findLocationOfHead();

    int getHeight() const {
        return HEIGHT;
    }
    int getWidth() const {
        return WIDTH;
    }

    std::vector<std::vector<int>> board;
        
private:
    int HEIGHT;
    int WIDTH;

    int newRow;
    int newCol;
};