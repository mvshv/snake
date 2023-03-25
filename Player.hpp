#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>

enum class Direction : int {
    LEFT = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3
};

struct DirectionOffset {
    int heightOffset;
    int widthOffset;
};

class Player {
    public:
        Player(std::string name = "XYZ");
        ~Player();

        DirectionOffset doMove(Direction direction);
        void updatePoints(int points);
        int getPoints() const;
        int getNumberOfBodyParts() const;
        
    private:
    std::string name;
    int points;
    int numberOfBodyParts;

};

#endif //PLAYER_HPP