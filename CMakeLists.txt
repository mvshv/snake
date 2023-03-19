cmake_minimum_required(VERSION 3.19)

project(TicTacToe)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake
    snake.cpp
    GameBoard.cpp
    Player.cpp
    SpecialEvents.cpp
)

add_subdirectory(tests)