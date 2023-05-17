#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "character.hpp"
#include "point.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
using namespace std;

namespace ariel
{
    class Team
    {
        vector<Cowboy *> cowboys;
        vector<Ninja *> ninjas;
        Character *teamLeader;

    public:
        // constructor
        Team(Character *leader);

        // functions
        virtual void add(Character *character);
        virtual void attack(Team *enemyTeam);
        virtual int stillAlive();
        virtual void print();
        virtual void destructor();
        virtual void setNewLeader();
        Character *closestVictimToLeader(Team *enemyTeam);
        bool isNinja(Character *teamMember);
        // getters and setters
        Character *getTeamLeader();
    };
}