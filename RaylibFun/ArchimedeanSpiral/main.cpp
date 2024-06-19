#include <raylib.h>
#include <cmath>


int main() 
{
    int width = 300;
    int height = 300;
    InitWindow(width, height, "Archemidean Spiral - raylib");

    SetTargetFPS(60);

    float a = 0.0f; // controls the starting radius
    float b = 1.0f; // controls the distance between the arms
    float centerX = GetScreenWidth() / 2;
    float centerY = GetScreenHeight() / 2;


    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (float theta = 0; theta <= PI * 10; theta += 0.01f){
            float r = a + b * theta;
            float x = centerX + r * cos(theta);
            float y = centerY + r * sin(theta);
            DrawPixel(static_cast<int>(x), static_cast<int>(y), RED);

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}