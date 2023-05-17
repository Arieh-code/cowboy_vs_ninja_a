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
        void add(Character * character) override;
        int stillAlive() override;
        void print() override;
        void attack(Team* enemyTeam) override;
        void setNewLeader() override;
        void destructor() override;
    };
}