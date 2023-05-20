#pragma once
#include "Character.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Ninja : public Character
    {
        int speed;

    public:
        // constructor
        Ninja(Point position, int score, string name);
        // functions
        void move(Character *enemy);
        void slash(Character *enemy);
        

        // getters and setters
        int getSpeed();
        void setSpeed(int num);
    };

  
    
   
}