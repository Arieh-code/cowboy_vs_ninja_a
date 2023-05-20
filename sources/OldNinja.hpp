#pragma once
#include "Ninja.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, Point position);
    };
}
  