#pragma once

#include <raylib.h>
#include <deque>
#include "grid.hpp"

class Game
{
public:
    Snake snake;
    Cell cell;
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;

    Game();

    void gameOver();

    void draw();

    void update();

    void checkFoodCollision();

    void checkBoundary();

    void makeItRun();

    void checkSelfCollision();
};