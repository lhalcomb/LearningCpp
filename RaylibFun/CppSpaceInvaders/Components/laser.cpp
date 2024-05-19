#include "../headerFiles/laser.hpp"
#include "../headerFiles/colors.hpp"

#include <iostream>

Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
    active = true;
}

void Laser::Draw()
{
    //Color yellow = {243, 216, 63, 255};
    if (active)
    {
        DrawRectangle(position.x, position.y, 4, 15, Colors::Yellow);
    }
    
}

void Laser::Update()
{   
    position.y += speed;

    if (active)
    {
        if (position.y > GetScreenHeight() || position.y < 0)
        {
            active = false;
            //std::cout << "Laserbeam is Inactive" << std::endl;
        }
    }
    
}