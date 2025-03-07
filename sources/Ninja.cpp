#include "Ninja.hpp"
using namespace ariel;

Ninja::Ninja(Point position, int score, string name)
    : Character(position, score, name), speed(0)
{
}

void Ninja::move(Character *enemy)
{
    Point newLocation = getLocation().moveTowards(getLocation(), enemy->getLocation(), speed);
    // this.setPosition(newLocation);
    setPosition(newLocation);
}

void Ninja::slash(Character *enemy)
{
    if(enemy == this){
        throw runtime_error("Can't slash yourself");
    }
    if(!enemy->isAlive()){
        throw runtime_error("Can't attack dead enemy");
    }
    if(!isAlive()){
        throw runtime_error("Can't attack while being dead");
    }
    if (this->isAlive() && distance(enemy) < 1)
    {
        enemy->hit(40);
    }
}

void Ninja::setSpeed(int speed)
{
    this->speed = speed;
}

int Ninja::getSpeed()
{
    return speed;
}
