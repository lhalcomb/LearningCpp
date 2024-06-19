//The initial game library that is being used. 
#include <raylib.h>

/*

 The string library ended up being useful for conversion purposes.
 This was for the score mechanic. 

*/
#include <string>

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

Things to add: 
   - Add sounds, maybe something goofy. Personally I love the noise the moving aliens make. 
   - Make it original. In other words, change the colors, images, font, etc.
   - Add a start screen. One that displays 1 Player Original or 1 Player AI version, etc.
   - Add a pause menu
   - Add Levels and increase the difficulty dependent on the aliens getting closer to player.
   

*/

using namespace std;

string FormatWithLeadingZeros( int number, int width)
{
    string numberText = to_string(number);
    int leadingZeros = width - numberText.length();

    return numberText = string(leadingZeros, '0') + numberText;
}

int main()
{   
    //Color gray = {29, 29, 27, 255};

    int offset = 50;
    int windowWidth = 750;
    int windowHeigth = 700;

    InitWindow(windowWidth + offset, windowHeigth + 2 * offset, "Space Invaders");
    SetTargetFPS(60);

    Font font = LoadFontEx("../Font/monogram.ttf", 64, 0, 0);
    Texture2D spaceshipImage = LoadTexture("../Graphics/spaceship.png");

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
        

        if (game.run) {
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, Colors::Yellow);
        }else{ 
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, Colors::Yellow);
        }


        float x = 50.0;

        for (int i = 0; i < game.lives; i++){
                DrawTextureV(spaceshipImage, {x, 745}, WHITE);
                x += 50;
        }

        DrawTextEx(font, "SCORE ", {50, 15}, 34, 2, Colors::Yellow);
        string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, Colors::Yellow);

        DrawTextEx(font, "HIGH-SCORE", {570, 15}, 34, 2, Colors::Yellow);
        string highscoreText = FormatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(), {655, 40}, 34, 2, Colors::Yellow);

        game.Draw();
        EndDrawing();

    }

    CloseWindow();
}