#pragma once
#include "character.hpp"
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
        string print() override;
        const std::type_info &getType() const override;

        // getters and setters
        int getSpeed();
        void setSpeed(int num);
    };

    class OldNinja : public Ninja
    {
        int speed;
    public:
        OldNinja(string name, Point position);
    };
    class TrainedNinja : public Ninja
    {
        int speed;
    public:
        TrainedNinja(string name, Point position);
    };
    class YoungNinja : public Ninja
    {
        int speed;
    public:
        YoungNinja(string name, Point position);
    };
}