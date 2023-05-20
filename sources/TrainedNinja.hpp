#pragma once
#include "Ninja.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point position);
    };
}