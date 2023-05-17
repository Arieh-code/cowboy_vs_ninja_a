#include "ninja.hpp"
using namespace ariel;

Ninja::Ninja(Point position, int score, string name)
    : Character(position, score, name), speed(0)
{
}

OldNinja::OldNinja(string name, Point position)
    : Ninja(position, 150, name), speed(8) {}

TrainedNinja::TrainedNinja(string name, Point position)
    : Ninja(position, 120, name), speed(12) {}

YoungNinja::YoungNinja(string name, Point position)
    : Ninja(position, 100, name), speed(14){}

void Ninja::move(Character * enemy)
{
}

void Ninja::slash(Character *enemy)
{
}

string Ninja::print()
{
    return "";
}

const std::type_info &Ninja::getType() const {
    return typeid(Ninja);
}
