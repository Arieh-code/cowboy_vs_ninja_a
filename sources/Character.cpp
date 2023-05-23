#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
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
    else
    {
        return false;
    }
}

double Character::distance(Character *other)
{
    return position.distance(other->position);
}

void Character::hit(int points)
{
    if(points < 0){
        throw invalid_argument("hit is negative");
    }
    this->hits -= points;
}

string Character::print()
{
    stringstream print;
    if (isAlive())
    {
        print << this->getName() << " " << this->getHits() << " " << this->getLocation().print();
        return print.str();
    }
    if (dynamic_cast<Ninja *>(this) != nullptr)
    {
        print << "N"
              << " (" << this->getName() << ")";
        return print.str();
    }
    else if (dynamic_cast<Cowboy *>(this) != nullptr)
    {
        print << "C"
              << " (" << this->getName() << ")";
        return print.str();
    }
    else
    {
        print << "Unassigned Character " << this->getName();
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

bool Character::getInTeam()
{
    return inTeam;
}

void Character::setInTeam(bool var)
{
    inTeam = var;
}