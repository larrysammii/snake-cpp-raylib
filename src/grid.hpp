#pragma once

#include <raylib.h>
#include <deque>

struct Cell
{
    int size = 30;
    int count = 25;
};

struct Direction
{
    Vector2 up = {0, -1};
    Vector2 down = {0, 1};
    Vector2 left = {-1, 0};
    Vector2 right = {1, 0};
};

class Snake
{
public:
    std::deque<Vector2> body;
    Vector2 snake_direction = {1, 0};
    double lastUpdateTime;
    Snake();

    bool eventTrigger(double interval);

    void draw();
    void move();
    void navigate();
};

class Food
{
private:
    Texture2D texture;

public:
    Vector2 position;

    Food();
    ~Food();

    void draw();
    Vector2 generateRandomPosition();
};