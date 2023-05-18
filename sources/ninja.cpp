#include "ninja.hpp"
using namespace ariel;

Ninja::Ninja(Point position, int score, string name)
    : Character(position, score, name), speed(0)
{
}

OldNinja::OldNinja(string name, Point position)
    : Ninja(position, 150, name)
{
    speed = 8;
}

TrainedNinja::TrainedNinja(string name, Point position)
    : Ninja(position, 120, name)
{
    speed = 12;
}

YoungNinja::YoungNinja(string name, Point position)
    : Ninja(position, 100, name)
{
    speed = 14;
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
}

// string Ninja::print()
// {
//     return "";
// }

int Ninja::getSpeed()
{
    return speed;
}

// const std::type_info &Ninja::getType() const {
//     return typeid(Ninja);
// }
