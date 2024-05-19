#include "../headerFiles/game.hpp"
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
    obstacles = createObstacles();
    aliens = createAliens();
    aliensDirection = 1;
    timeLastAlienFired = 0;
    timeLastSpawned = 0.0;
    mysterShipSpawnInterval = GetRandomValue(10, 20);
    
    

}

Game::~Game()
{
    Alien::UnloadImages();

}

void Game::Update()
{
    double currentTime = GetTime();
    if(currentTime - timeLastSpawned > mysterShipSpawnInterval){
        mysteryship.Spawn();
        timeLastSpawned = GetTime();
        mysterShipSpawnInterval = GetRandomValue(10, 20);
    }

    for (auto& laser: spaceship.lasers)
    {
        laser.Update();
    }
    MoveAliens();

    AlienShootLaser();
    for (auto& laser: alienLasers){
        laser.Update();
    }

    DeleteInactiveLasers();
    //cout << "Vector Size: " << spaceship.lasers.size() << endl;
    mysteryship.Update();
}

void Game::Draw()
{
    spaceship.Draw();

    for (auto& laser: spaceship.lasers)
    {
        laser.Draw();
    }

    for (auto& obstacle: obstacles)
    {
        obstacle.Draw();
    }

    for (auto& alien: aliens)
    {
        alien.Draw();
    }

    for (auto& laser: alienLasers){
        laser.Draw();
    }

    mysteryship.Draw();
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

    for (auto it = alienLasers.begin(); it != alienLasers.end();){
        if (!it -> active)
        {
            it = alienLasers.erase(it);
        }else{
            ++ it;
        }
    }


}

std::vector<Obstacle> Game::createObstacles()

{
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * obstacleWidth))/5;

    for (int i = 0; i < 4; i++)
    {
        float offsetX = (i + 1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
    }

    return obstacles;
}

std::vector<Alien> Game::createAliens()
{
     std::vector<Alien> aliens;
     

     for (int rowOfAliens = 0; rowOfAliens < 5; rowOfAliens++)
     {
        for (int columnOfAliens = 0; columnOfAliens < 11; columnOfAliens++){
            //In styling terms, this can be considered as padding-around for the aliens
            int cellSize = 55; //Also each image is 55 pixels wide
            
            //New Grid location for aliens
            int alienOffsetX = 75; 
            int alienOffsetY = 110;

            //Alien types in their corresponding rows
            int alienType;
            if(rowOfAliens == 0){
                alienType = 3;
            }else if (rowOfAliens == 1 || rowOfAliens == 2){
                alienType = 2;
            }else{
                alienType = 1;
            }

            float x = alienOffsetX + columnOfAliens * cellSize;
            float y = alienOffsetY + rowOfAliens * cellSize;
            aliens.push_back(Alien(alienType, {x, y}));
        }
     }
     return aliens;
}

void Game::MoveAliens()
{
    for (auto& alien: aliens)
    {
        if (alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth())
        {
            aliensDirection = -1;
            MoveDownAliens(4);
        }
        if (alien.position.x < 0)
        {
            aliensDirection = 1;
            MoveDownAliens(4);
        }

        alien.Update(aliensDirection);
    }

}

void Game::MoveDownAliens(int distance)
{
    for (auto& alien: aliens)
    {
        alien.position.y += distance;
    }
}

void Game::AlienShootLaser()
{
    double currentTime = GetTime();
    if ((currentTime - timeLastAlienFired > alienLaserShootInterval) && !aliens.empty()){
        int randomIndex = GetRandomValue(0, aliens.size() - 1);
        Alien& alien = aliens[randomIndex];
        alienLasers.push_back(Laser({alien.position.x + alien.alienImages[alien.type - 1].width/2, 
                                    alien.position.y + alien.alienImages[alien.type -1].height}, 6));
        timeLastAlienFired = GetTime();
    }
    
}
