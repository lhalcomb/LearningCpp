#include "game.hpp"

/* 
File: game.hpp Author: Layden Halcomb

Description: 
    This file includes the header file for the game class. 
    Here we are able to give the constructor and desctructor ways to cleanly 
    manage the game functionality
 */

Game::Game()
{
}

Game::~Game()
{
}

void Game::Draw()
{
    spaceship.Draw();
}

void Game::HandlePlayerInput()
{
    /* 
    This is pretty straight forward here. 
    All of this is for the players spaceship
    */

    if (IsKeyDown(KEY_LEFT))
    {
        spaceship.MoveLeft();
    }

    else if (IsKeyDown(KEY_RIGHT))
    {
        spaceship.MoveRight();
    }

}