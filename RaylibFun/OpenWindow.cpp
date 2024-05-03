#include <raylib.h>

int main(){
    InitWindow(400, 600, "My First RayLib Window");

    while (!WindowShouldClose()){
        BeginDrawing(); // Begin drawing frame

        ClearBackground(RAYWHITE); // Clear the background with a specific color (here, light gray)

        DrawLine(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK); // Draw the diagonal line

        EndDrawing(); // End of frame

        if (IsKeyPressed(KEY_ESCAPE)){
            CloseWindow();
            return 0;
        }
        // Check if the window should close
        if (WindowShouldClose()) {
            CloseWindow();
            return 0;
        }

    }

    CloseWindow();
    return 0;
}
