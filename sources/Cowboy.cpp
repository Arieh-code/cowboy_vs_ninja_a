#include "Cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string name, Point position)
    : Character(position, 110, name), number_of_bullets(6)
{
}

int Cowboy::get_number_of_bullets()
{
    return number_of_bullets;
}

void Cowboy::set_number_of_bullets(int bullets)
{
    this->number_of_bullets = bullets;
}

void Cowboy::shoot(Character *enemy)
{
    if (this->isAlive() && number_of_bullets > 0)
    {
        enemy->hit(10);
        number_of_bullets -= 1;
    }
    else
    {
        reload();
    }
}

bool Cowboy::hasboolets()
{
    return number_of_bullets > 0 ? true : false;
}

void Cowboy::reload()
{
    number_of_bullets = 6;
}
