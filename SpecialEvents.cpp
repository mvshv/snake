#include "SpecialEvents.hpp"
#include "GameBoard.hpp"

SpecialEvents::SpecialEvents(){ }

SpecialEvents::~SpecialEvents(){ }

void SpecialEvents::addFood(GameBoard& gameBoard) {

    int height = rand() % (gameBoard.getHeight() - 2) + 1;
    int width = rand() % (gameBoard.getWidth() - 2) + 1;

    gameBoard.setSpecialObjectAt(height, width, Objects::FOOD);
}