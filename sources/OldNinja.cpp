#include "OldNinja.hpp"
using namespace ariel;

OldNinja::OldNinja(string name, Point position)
    : Ninja(position, 150, name)
{
    this -> setSpeed(8);
}