#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Team.hpp"
using namespace std;

namespace ariel{
    class SmartTeam : public Team{
        vector<Character*> teamMembers;
    public:
        SmartTeam(Character *);
        void add(Character * character);
        int stillAlive();
        void print() override;
        void attack(Team* enemyTeam) override;
        void setNewLeader();
        void destructor() override;
    };
}