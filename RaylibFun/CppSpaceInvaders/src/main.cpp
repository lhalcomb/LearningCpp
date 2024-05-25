//The initial game library that is being used. 
#include <raylib.h>


//Project oriented header files 
#include "../headerFiles/spaceship.hpp"
#include "../headerFiles/game.hpp"
#include "../headerFiles/colors.hpp"




//This is imported for debugging purposes and might be deprecated later
#include <iostream>

/* 
File: main.cpp Author: Layden Halcomb

Description: 
The following is the file that runs the entire project. 

*/

using namespace std;

int main()
{   
    //Color gray = {29, 29, 27, 255};

    int offset = 50;
    int windowWidth = 750;
    int windowHeigth = 700;

    InitWindow(windowWidth + offset, windowHeigth + 2 * offset, "Space Invaders");
    SetTargetFPS(60);

    Game game;
    
    
    //Debugging Section
    /*cout<< "Debugging: "<<endl;
    cout<< "Spaceship x position: " << game.spaceship.position.x <<endl;
    cout<< "Spaceship y position: " <<game.spaceship.position.y <<endl;*/
    
    

    while(!WindowShouldClose()) 
    {
        game.HandlePlayerInput();
        game.Update();
        BeginDrawing();
        ClearBackground(Colors::Gray);
        DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, 2, Colors::Yellow);
        DrawLineEx({25, 730}, {755, 730}, 3, Colors::Yellow);
        game.Draw();

        EndDrawing();

    }

    CloseWindow();
}