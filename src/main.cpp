#include <raylib-cpp.hpp>
// #include <raylib.h>
#include "grid.hpp"

using namespace std;

int main()
{

    // Initialization
    Cell cell;
    int screenWidth = cell.size * cell.count;
    int screenHeight = cell.size * cell.count;

    // raylib::Color textColor(LIGHTGRAY);
    // InitWindow(screenWidth, screenHeight, "Snake");
    raylib::Window w(screenWidth, screenHeight, "Snake");
    Food food = Food();
    Snake snake = Snake();
    Direction direction;
    double *lastUpdateTime = &snake.lastUpdateTime;
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {

        // Draw
        BeginDrawing();

        if (snake.eventTrigger(0.2))
        {
            snake.move();
        }

        snake.navigate();

        ClearBackground(RAYWHITE);

        food.draw();
        snake.draw();

        // textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
        EndDrawing();
    }

    return 0;
}