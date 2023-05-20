#include "YoungNinja.hpp"
using namespace ariel;

YoungNinja::YoungNinja(string name, Point position)
    : Ninja(position, 100, name)
{
    this->setSpeed(14);
}