#include "../headerFiles/spaceship.hpp"



Spaceship::Spaceship()
{
    image = LoadTexture("../Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = (GetScreenHeight() - image.height);
    lastFireTime = 0.0;
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::Draw()
{
    DrawTextureV(image, position, WHITE);
}

/*
    The following methods are implemented to allow the 
    spaceship to move along a horizontal axis.  This just 
    uses some simple x axis position movement. Nothing too serious. 
*/
int PIXEL_SPEED = 5;
void Spaceship::MoveLeft()
{
    position.x -= PIXEL_SPEED;
 //The following conditional generates a boundary for the left of screen
    if(position.x < 0)
    {
        position.x = 0;
    }
}

void Spaceship::MoveRight()
{
    position.x += PIXEL_SPEED;
//The following conditional generates a boundary for the right of the screen
    if(position.x > GetScreenWidth() - image.width){
        position.x = GetScreenWidth() - image.width;
    }
}
/*
    The following method here is used for calculating where the lasers fire 
    and the speed associated with it respectively. 
*/
void Spaceship::FireLaser()
{
    if (GetTime() - lastFireTime >= 0.35)
    {
        int FireLaserSpeed = -6;
        lasers.push_back(Laser({position.x + image.width/2 - 2,position.y}, FireLaserSpeed));
        lastFireTime = GetTime();
    }
}
