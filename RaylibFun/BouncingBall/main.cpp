#include <iostream>
#include <raylib.h>

using namespace std;

void ballMove(int &ball_x, int &ball_y, int &ball_speed_x, int &ball_speed_y, int &ball_radius){

        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if (ball_x + ball_radius >= GetScreenWidth() || ball_x - ball_radius <= 0)
        {
            ball_speed_x *= -1;
        }

        if (ball_y + ball_radius >= GetScreenHeight() || ball_y - ball_radius <= 0)
        {
            ball_speed_y *= -1;
        }


        DrawCircle(ball_x, ball_y, ball_radius, WHITE);
}

void rectangleMove(Vector2 &position, int &rect_speed_x, int &rectWidth, int &rectHeight){
    position.x += rect_speed_x; 

    if (position.x + rectWidth >= GetScreenWidth() || position.x <= 0)
    {
        rect_speed_x *= -1;
    }
    DrawRectangle(position.x, position.y, rectWidth, rectHeight, BLACK);
}

int main() {

    Color Dark_Green = Color{ 20, 160, 133, 255 };

    const int screenWidth = 800;
    const int screenHeight = 600;
    int ball_x = 150; int ball_y = 150;
    int ball_speed_x = 5; int ball_speed_y = 5;
    int ball_radius = 15; 

    Vector2 recPosition = {100, 100}; 
    int rect_speed_x = 10; 
    int rectWidth = 100;
    int rectHeight = 100;




    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Dark_Green);
        ballMove(ball_x, ball_y, ball_speed_x, ball_speed_y, ball_radius);
        rectangleMove(recPosition, rect_speed_x, rectWidth, rectHeight);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}