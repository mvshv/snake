cmake_minimum_required(VERSION 3.19)

project(TicTacToe)

find_package(GTest REQUIRED)
find_package(Curses REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake
    snake.cpp
    GameBoard.cpp
    Player.cpp
    SpecialEvents.cpp
)

target_link_libraries(snake PRIVATE ${CURSES_LIBRARIES})