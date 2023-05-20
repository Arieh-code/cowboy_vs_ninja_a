#include "TrainedNinja.hpp"
using namespace ariel;
TrainedNinja::TrainedNinja(string name, Point position)
    : Ninja(position, 120, name)
{
    this->setSpeed(12);
}