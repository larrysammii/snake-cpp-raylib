#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "grid.hpp"

Cell cell;
Direction direction;

Food::Food()
{

    Image image = LoadImage("assets/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = generateRandomPosition();
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::draw()
{
    DrawTexture(texture, position.x * cell.size, position.y * cell.size, WHITE);

    // DrawRectangle(position.x * cell.size, position.y * cell.size, cell.size, cell.size, RED);
}

Vector2 Food::generateRandomPosition()
{
    float x = GetRandomValue(0, cell.count - 1);
    float y = GetRandomValue(0, cell.count - 1);
    return Vector2{x, y};
}

Snake::Snake()
{
    body = {Vector2{10, 10}, Vector2{11, 10}, Vector2{12, 10}};
    lastUpdateTime = 0;
}

void Snake::draw()
{
    for (unsigned int i = 0; i < body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{x * cell.size, y * cell.size, (float)cell.size, (float)cell.size};

        DrawRectangleRounded(segment, 0.5, 3, DARKGREEN);
        // DrawRectangle(x * cell.size, y * cell.size, cell.size, cell.size, DARKGREEN);
    }
}

void Snake::move()
{
    body.pop_back();
    body.push_front(Vector2Add(body[0], snake_direction));
}

bool Snake::eventTrigger(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void Snake::navigate()
{
    int key = GetKeyPressed();

    switch (key)
    {
    case KEY_UP:
        if (snake_direction.y != 1)
        {
            snake_direction = direction.up;
        }
        break;

    case KEY_DOWN:
        if (snake_direction.y != -1)
        {
            snake_direction = direction.down;
        }
        break;

    case KEY_LEFT:
        if (snake_direction.x != 1)
        {
            snake_direction = direction.left;
        }
        break;

    case KEY_RIGHT:
        if (snake_direction.x != -1)
        {
            snake_direction = direction.right;
        }
        break;

    default:
        break;
    }
}