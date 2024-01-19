#include <raylib-cpp.hpp>
// #include <raylib.h>
#include "grid.hpp"
#include "game.hpp"

using namespace std;

int main()
{

    // Initialization
    // Should've separated a lot of these in different header files but whatever.
    Cell cell;
    int offset = 75;
    int screenWidth = cell.size * cell.count + offset * 2;
    int screenHeight = cell.size * cell.count + offset * 2;

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
        DrawText("snake", offset - 5, 20, 40, DARKGREEN);
        DrawText(("score: " + to_string(game.score)).c_str(), offset - 5, offset + cell.size * cell.count + 10, 40, DARKGREEN);
        game.draw();

        game.update();

        ClearBackground(DARKGRAY);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cell.size * cell.count + 10, (float)cell.size * cell.count + 10}, 5, DARKGREEN);

        // if (game.running == false)
        // {
        //     game.makeItRun();
        // }

        // textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
        EndDrawing();
    }

    return 0;
}