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
        int updatePoints(int points);
        
    private:
    std::string name;
    int points;

};
