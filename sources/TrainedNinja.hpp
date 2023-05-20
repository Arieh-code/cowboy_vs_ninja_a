#pragma once
#include "Character.hpp"
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