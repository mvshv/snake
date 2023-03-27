#include "SpecialEvents.hpp"
#include "GameBoard.hpp"


SpecialEvents::SpecialEvents(){ }

SpecialEvents::~SpecialEvents(){ }

void SpecialEvents::addFood(GameBoard& gameBoard) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    std::uniform_int_distribution<int> heightDistribution(1, gameBoard.getHeight() - 4);
    std::uniform_int_distribution<int> widthDistribution(1, gameBoard.getWidth() - 4);

    int height = heightDistribution(generator);
    int width = widthDistribution(generator);

    gameBoard.setSpecialObjectAt(height, width, Objects::FOOD);
}

void SpecialEvents::addExtaFood(GameBoard& gameBoard) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    std::uniform_int_distribution<int> heightDistribution(5, gameBoard.getHeight() - 4);
    std::uniform_int_distribution<int> widthDistribution(5, gameBoard.getWidth() - 4);

    int height = heightDistribution(generator);
    int width = widthDistribution(generator);

    gameBoard.setExtraObjectAt(height, width, Objects::EXTRA_FOOD);
}

