#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
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