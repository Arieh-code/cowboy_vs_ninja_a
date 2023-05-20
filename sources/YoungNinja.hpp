#pragma once
#include "Ninja.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel{
     class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, Point position);
    };
}