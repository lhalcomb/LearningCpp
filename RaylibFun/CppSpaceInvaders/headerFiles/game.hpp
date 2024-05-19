#pragma once
#include "../headerFiles/spaceship.hpp"
#include "../headerFiles/obstacle.hpp"
#include "../headerFiles/alien.hpp"
#include "../headerFiles/mysteryship.hpp"

/*

File: game.hpp Author: Layden Halcomb

Description: 
    This file serves as a container for all of the elements that run the game.
    It includes the spaceships, objects, aliens, and the game state.
    It also includes methods that manage the game logic. Such as, updating
    the position of the game objects, checking for collisions, updating score, 
    & handling input. 
*/

class Game {

    public: 
        Game(); //Constructor 
        ~Game(); //Destructor
    //Methods
        void Draw(); 
        void Update();
        void HandlePlayerInput();

    private: //go back and change this to private later
        void DeleteInactiveLasers();
        std::vector<Obstacle> createObstacles();
        std::vector<Alien> createAliens();
        void MoveAliens();
        void MoveDownAliens(int distance);
        void AlienShootLaser();
        Spaceship spaceship;

        std::vector<Obstacle> obstacles;
        std::vector<Alien> aliens;
        int aliensDirection;

        std::vector<Laser> alienLasers;
        constexpr static float alienLaserShootInterval = 0.75;
        float timeLastAlienFired;

        MysteryShip mysteryship;
        float mysterShipSpawnInterval;
        float timeLastSpawned;



};