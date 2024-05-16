//The initial game library that is being used. 
#include <raylib.h>

//Project oriented header files 
#include "spaceship.hpp"
#include "game.hpp"

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
    Color gray = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeigth = 700;

    InitWindow(windowWidth, windowHeigth, "Space Invaders");
    SetTargetFPS(60);

    Game game;

    //Debugging Section
    cout<< "Debugging: "<<endl;
    cout<< "Spaceship x position: " << game.spaceship.position.x <<endl;
    cout<< "Spaceship y position: " <<game.spaceship.position.y <<endl;
    
    

    while(!WindowShouldClose()) 
    {
        game.HandlePlayerInput();
        BeginDrawing();
        ClearBackground(gray);
        game.Draw();

        EndDrawing();

    }

    CloseWindow();
}