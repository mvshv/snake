#include "Player.hpp"

Player::Player(std::string name) : name(name) {}

Player::~Player(){}

DirectionOffset Player::doMove(Direction direction) {

    DirectionOffset directionOffset;

      switch(direction) {
    case Direction::LEFT:
        directionOffset.heightOffset = 0;
        directionOffset.widthOffset = -1;
     break;

      case Direction::UP:
        directionOffset.heightOffset = -1;
        directionOffset.widthOffset = 0;       
     break;
    
     case Direction::RIGHT:
        directionOffset.heightOffset = 0;
        directionOffset.widthOffset = 1;
     break;

     case Direction::DOWN:
        directionOffset.heightOffset = 1;
        directionOffset.widthOffset = 0;
     break;

     default:
      std::cout << "wrong move\n";
      break;
  }
  return directionOffset;
}

int Player::updatePoints(int points) {
    this->points += points;

    return this->points;
}
