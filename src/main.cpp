#include <raylib-cpp.hpp>
// #include <raylib.h>
#include "grid.hpp"
#include "game.hpp"

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
    Game game;

    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {

        // Draw
        BeginDrawing();
        game.draw();

        game.update();

        ClearBackground(RAYWHITE);

        // if (game.running == false)
        // {
        //     game.makeItRun();
        // }

        // textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
        EndDrawing();
    }

    return 0;
}