#pragma once
#include "spaceship.hpp"

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

    public: //go back and change this to private later
        Spaceship spaceship;
};