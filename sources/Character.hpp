#pragma once
#include "Point.hpp"
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
        bool inTeam = false;

    public:
        // constructors
        Character();
        Character(Point position, int hits, string name);
        Character(const Character &) = delete;            // Copy constructor
        Character &operator=(const Character &) = delete; // Copy assignment operator
        Character(Character &&) = delete;                 // Move constructor
        Character &operator=(Character &&) = delete;      // Move assignment operator

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
        void setName(string name);
        void setInTeam(bool var);
        bool getInTeam();
        virtual const std::type_info &getType() const;
    };
}
