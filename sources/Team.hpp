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
        Team(const Team &) = delete;
        Team &operator=(const Team &) = delete;
        Team(Team &&) = delete;
        Team &operator=(Team &&) = delete;
        // destructor
        virtual ~Team();

        // functions
        void add(Character *character);
        virtual void attack(Team *enemyTeam);
        int stillAlive();
        virtual void print();
        virtual void destructor();

        Character *closestVictimToLeader(Team *enemyTeam);
        void closestToLeader();
        // getters and setters
        Character *getTeamLeader();
        void setNewLeader(Character *character);
        vector<Character *> &getTeamMembers();
    };
}