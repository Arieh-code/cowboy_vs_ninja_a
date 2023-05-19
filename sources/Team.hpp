#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "character.hpp"
#include "point.hpp"
#include "cowboy.hpp"
#include "ninja.hpp"
using namespace std;

namespace ariel
{
    class Team
    {
        vector<Character *> teamMembers;
        Character *teamLeader;

    public:
        // constructor
        Team(Character *leader);
        // destructor
        virtual ~Team();

        // functions
        void add(Character *character);
        virtual void attack(Team *enemyTeam);
        int stillAlive();
        virtual void print();
        virtual void destructor();
        void setNewLeader(Character *character);
        Character *closestVictimToLeader(Team *enemyTeam);
        void closestToLeader();
        // getters and setters
        Character *getTeamLeader();
    };
}