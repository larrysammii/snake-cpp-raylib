#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "grid.hpp"
#include "game.hpp"
#include <deque>

// Cell
Cell cell;

// Direction
Direction direction;

// Not sure if this is right
// Game game;

// Food logic
Food::Food(std::deque<Vector2> snakebody)
{

    Image image = LoadImage("assets/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = generateRandomPosition(snakebody);
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::draw()
{
    float offset = 75;

    DrawTexture(texture, offset + position.x * cell.size, offset + position.y * cell.size, WHITE);

    // DrawRectangle(position.x * cell.size, position.y * cell.size, cell.size, cell.size, RED);
}

// Check if food next to snake
// I dont really get this
bool Food::elementInDeque(Vector2 snakefood, std::deque<Vector2> snakebody)
{
    for (unsigned int i = 0; i < snakebody.size(); i++)
    {
        if (Vector2Equals(snakefood, snakebody[i]))
        {
            return true;
        }
    }
    return false;
}

Vector2 Food::generateRandomCell()
{
    // cell.count - 2 to prevent food from spawning on the edge
    float x = GetRandomValue(0, cell.count - 2);
    float y = GetRandomValue(0, cell.count - 2);
    return Vector2{x, y};
}

Vector2 Food::generateRandomPosition(std::deque<Vector2> body)
{

    Vector2 position = generateRandomCell();

    while (elementInDeque(position, body))
    {
        // -2 same reason as above, but i dont know why it doesnt work yet
        float x = GetRandomValue(0, cell.count - 2);
        float y = GetRandomValue(0, cell.count - 2);
        position = Vector2{x, y};
    }
    return position;
}

// Snake logic
Snake::Snake()
{
    body = {Vector2{10, 10}, Vector2{11, 10}, Vector2{12, 10}};
    lastUpdateTime = 0;
}

void Snake::draw()
{
    float offset = 75;
    for (unsigned int i = 0; i < body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{offset + x * cell.size, offset + y * cell.size, (float)cell.size, (float)cell.size};

        DrawRectangleRounded(segment, 0.5, 3, DARKGREEN);
        // DrawRectangle(x * cell.size, y * cell.size, cell.size, cell.size, DARKGREEN);
    }
}

void Snake::reset()
{
    body = {Vector2{10, 10}, Vector2{11, 10}, Vector2{12, 10}};
}

void Snake::update()
{
    body.push_front(Vector2Add(body[0], snake_direction));
    // Honestly I dont get this,
    // like you add a segment first regardless,
    // then you check if addSegment is true (then ignore),
    // else remove it again? A bit redundant?
    if (addSegment == true)
    {
        // body.push_front(Vector2Add(body[0], snake_direction));
        addSegment = false;
    }
    else
    {
        body.pop_back();
        // body.push_front(Vector2Add(body[0], snake_direction));
    }
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