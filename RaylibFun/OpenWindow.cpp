#include <raylib.h>

int main(){
    const int screenWidth = 400;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "My First RayLib Window");

    while (!WindowShouldClose()){
        BeginDrawing(); // Begin drawing frame

        ClearBackground(RAYWHITE); // Clear the background with a specific color (here, light gray)

        //DrawLine(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK); // Draw the diagonal line

        float widthOfScreen = static_cast<float>(screenWidth);
        float heightOfScreen = static_cast<float>(screenHeight);
        DrawLineEx((Vector2){0.0f,0.0f}, (Vector2){widthOfScreen, heightOfScreen}, 5, GREEN);   // Draw a line (using triangles/quads)


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
