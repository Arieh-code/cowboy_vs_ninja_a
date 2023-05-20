#pragma once
#include <iostream>
#include <string>
#include "character.hpp"
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
        int number_of_bullets;

    public:
        Cowboy(string name, Point position);
        int get_number_of_bullets();
        void set_number_of_bullets(int bullets);
        void shoot(Character *enemy);
        bool has_bullets();
        void reload();
    };
}