#include "ninja.hpp"
using namespace ariel;

Ninja::Ninja(Point position, int score, string name)
    : Character(position, score, name), speed(0)
{
}

OldNinja::OldNinja(string name, Point position)
    : Ninja(position, 150, name)
{
    this -> setSpeed(8);
}

TrainedNinja::TrainedNinja(string name, Point position)
    : Ninja(position, 120, name)
{
    this->setSpeed(12);
}

YoungNinja::YoungNinja(string name, Point position)
    : Ninja(position, 100, name)
{
    this->setSpeed(14);
}

void Ninja::move(Character *enemy)
{
    Point newLocation = getLocation().moveTowards(getLocation(), enemy->getLocation(), speed);
    // this.setPosition(newLocation);
    setPosition(newLocation);
}

void Ninja::slash(Character *enemy)
{
    if (this->isAlive() && distance(enemy) < 1)
    {
        enemy->hit(40);
    }
    else{
        move(enemy);
    }
    
}

void Ninja::setSpeed(int speed){
    this->speed = speed;
}

int Ninja::getSpeed()
{
    return speed;
}


