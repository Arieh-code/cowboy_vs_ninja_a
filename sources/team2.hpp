#pragma once
#include "Team.hpp"
using namespace std;

namespace ariel
{
    class Team2 : public Team
    {
        vector<Character *> teamMembers;

    public:
        Team2(Character *);
        void add(Character * character) override;
        int stillAlive() override;
        void print() override;
        void attack(Team* enemyTeam) override;
        void setNewLeader() override;
        void destructor() override;


    };
}