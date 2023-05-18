#include "character.hpp"
#include "ninja.hpp"
#include "cowboy.hpp"
using namespace ariel;

Character::Character(Point position, int hits, string name)
    : position(position), hits(hits), name(name)
{
}

Character::Character()
    : position(), hits(0), name("")
{
}

Character::~Character()
{
}

bool Character::isAlive()
{
    if (hits > 0)
    {
        return true;
    }
    return false;
}

double Character::distance(Character *other)
{
    return position.distance(other->position);
}

void Character::hit(int points)
{
    this->hits -= points;
}

string Character::print()
{
    stringstream print;
    if (isAlive())
    {
        print << name << " " << hits << " " << position.print();
        return print.str();
    }
    if (dynamic_cast<Ninja *>(this) != nullptr)
    {
        print << "N"
              << " (" << name << ")";
        return print.str();
    }
    else if(dynamic_cast<Cowboy *>(this) != nullptr)
    {
        print << "C"
              << " (" << name << ")";
        return print.str();
    }
    else{
        print << "Unassigned Character " << name;
        return print.str();
    }
}

string Character::getName()
{
    return name;
}

Point Character::getLocation()
{
    return position;
}

int Character::getHits()
{
    return hits;
}

void Character::setHits(int amount)
{
    this->hits = amount;
}

void Character::setPosition(Point position)
{
    this->position = position;
}

const std::type_info &Character::getType() const
{
    return typeid(*this);
}