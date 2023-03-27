#ifndef SPECIALEVENTS_HPP
#define SPECIALEVENTS_HPP

#include <iostream>
#include <vector>

// Forward declaration of GameBoard class
class GameBoard;

class SpecialEvents {
    public:

    SpecialEvents();
    ~SpecialEvents();
    void addFood(GameBoard& gameBoard);
    void addExtaFood(GameBoard& gameBoard);

};
#endif //SPECIALEVENTS_HPP
