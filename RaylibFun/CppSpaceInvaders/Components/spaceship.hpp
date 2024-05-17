#pragma once 
#include <raylib.h>

class Spaceship{
    public:
        Spaceship();

        ~Spaceship();
        void Draw();

        void MoveLeft();
        void MoveRight();

        void FireLaser();

    public: //go back and change this to private later
        Texture2D image; 
        Vector2 position;

};