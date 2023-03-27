#include "Player.hpp"

Player::Player(std::string name) : 
    name(name),
    points(0),
    numberOfBodyParts(0) {}

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

void Player::eatedRegularFood(int points) {
    this->points += points;
    numberOfBodyParts++;
}
void Player::eatedExtraFood(int points) {
    this->points += points;
}

int Player::getPoints() const {
    return points;   
}

int Player::getNumberOfBodyParts() const {
    return numberOfBodyParts;
}
