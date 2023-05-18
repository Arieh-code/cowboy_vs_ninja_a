#pragma once
#include "point.hpp"
#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>
using namespace std;

namespace ariel
{
    class Character
    {
        string name;
        int hits;
        Point position;

    public:
        // constructors
        Character();
        Character(Point position, int hits, string name);

        // destructor
        virtual ~Character();
        // functions
        bool isAlive();
        double distance(Character *other);
        void hit(int points);
        virtual string print();
        // getters and setters
        string getName();
        Point getLocation();
        int getHits();
        void setHits(int amount);
        void setPosition(Point position);
        virtual const std::type_info &getType() const;
    };
}
