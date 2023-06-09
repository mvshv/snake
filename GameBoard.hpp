#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>

// Forward declaration of SpecialEvents class
class SpecialEvents;

enum class Objects {
    EMPTY = 0,
    SNAKE_HEAD = 1,
    SNAKE_BODY = 2,
    FOOD = 3,
    EXTRA_FOOD = 4,
    WALL = 5
};

struct HeadLocation{
    int ROW;
    int COL;
};

class BodyLocation {
public:
    BodyLocation(HeadLocation& location) {
        this->ROW = location.ROW;
        this->COL = location.COL;
    }
    
    int ROW;
    int COL;
};


class GameBoard {

public:
    GameBoard(int HEIGHT, int WIDTH, Player& player);
    void displayBoard() const;
    int doMove(int heightOffset, int widthOffset);
    bool checkCollision();
    void setSpecialObjectAt(int height, int width, Objects);
    void setExtraObjectAt(int height, int width, Objects );
    void getObjectAt(int height, int width);
    HeadLocation findLocationOfHead();

    int getHeight() const {
        return HEIGHT;
    }
    int getWidth() const {
        return WIDTH;
    }

    std::vector<std::vector<int> > board;
        
private:
    SpecialEvents *specialEvents;
    Player &player;
    std::vector<BodyLocation> bodyLocations;
    int HEIGHT;
    int WIDTH;

    int newRow;
    int newCol;
};

#endif // GAMEBOARD_HPP
