#include "game.hpp"
#include <iostream>

/* 
File: game.hpp Author: Layden Halcomb

Description: 
    This file includes the header file for the game class. 
    Here we are able to give the constructor and desctructor ways to cleanly 
    manage the game functionality
 */

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Update()
{
    for (auto& laser: spaceship.lasers)
    {
        laser.Update();
    }

    DeleteInactiveLasers();
    cout << "Vector Size: " << spaceship.lasers.size() << endl;
    
}

void Game::Draw()
{
    spaceship.Draw();

    for (auto& laser: spaceship.lasers)
    {
        laser.Draw();
    }
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

    if (IsKeyDown(KEY_SPACE))
    {
        spaceship.FireLaser();
    }
}

void Game::DeleteInactiveLasers()
{
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();){
        if (!it -> active)
        {
            it = spaceship.lasers.erase(it);
        }else{
            ++ it;
        }
    }
}
