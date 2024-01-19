#include <raylib.h>
#include <iostream>
#include "game.hpp"
#include "grid.hpp"
#include <raymath.h>

void Game::gameOver()
{

    running = false;
    snake.reset();
    score = 0;
}

void Game::draw()
{
    ClearBackground(RAYWHITE);

    food.draw();
    snake.draw();
}

void Game::update()
{
    if (running)
    {
        if (snake.eventTrigger(0.2))
        {
            checkFoodCollision();
            checkBoundary();
            checkSelfCollision();
            snake.update();
        }

        snake.navigate();
    }
    else
    {
        makeItRun();
    }
}

void Game::checkFoodCollision()
{
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.generateRandomPosition(snake.body);
        snake.addSegment = true;
        score++;
    }
}

void Game::checkBoundary()
{
    if (snake.body[0].x == cell.count || snake.body[0].x == -1)
    {
        gameOver();
    }
    if (snake.body[0].y == cell.count || snake.body[0].y == -1)
    {
        gameOver();
    }
}

void Game::checkSelfCollision()
{
    std::deque<Vector2> headlessbody = snake.body;
    headlessbody.pop_front();

    if (food.elementInDeque(snake.body[0], headlessbody))
    {
        gameOver();
    }
}

void Game::makeItRun()
{
    int key = GetKeyPressed();
    switch (key)
    {
    case KEY_SPACE:
        running = true;
        food.position = food.generateRandomPosition(snake.body);
        break;
    default:
        running = true;
        break;
    }
}

Game::Game()
{
    double *lastUpdateTime = &snake.lastUpdateTime;

    draw();
    update();
}