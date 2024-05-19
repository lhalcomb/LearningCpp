#pragma once 
#include <raylib.h>
#include <vector>

#include "../headerFiles/laser.hpp"

using namespace std;

class Spaceship{
    public:
        Spaceship();

        ~Spaceship();
        void Draw();

        void MoveLeft();
        void MoveRight();

        void FireLaser();
        vector<Laser> lasers;

    private: //go back and change this to private later... Done. 
        Texture2D image; 
        Vector2 position;
        double lastFireTime;

};