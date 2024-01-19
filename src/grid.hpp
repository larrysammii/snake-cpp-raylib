#pragma once

#include <raylib.h>
#include <deque>

// The grid
struct Cell
{
    int size = 30;
    int count = 25;
};

// Direction definition
struct Direction
{
    Vector2 up = {0, -1};
    Vector2 down = {0, 1};
    Vector2 left = {-1, 0};
    Vector2 right = {1, 0};
};

// Snake logic

class Snake
{
public:
    std::deque<Vector2> body;
    Vector2 snake_direction = {1, 0};
    double lastUpdateTime;
    bool addSegment;

    Snake();

    bool eventTrigger(double interval);

    void draw();
    void update();
    void navigate();
    void reset();
};

// Food logic
class Food
{
private:
    Texture2D texture;

public:
    Vector2 position;

    Food(std::deque<Vector2> snakebody);
    ~Food();

    void draw();

    bool elementInDeque(Vector2 snakefood, std::deque<Vector2> snakebody); // Check if food is in snake?
    Vector2 generateRandomCell();
    Vector2 generateRandomPosition(std::deque<Vector2> body);
};