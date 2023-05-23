#pragma once
#include "Team.hpp"
#include <iostream>
using namespace std;

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
        void print() override;
        void attack(Team *enemyTeam) override;
        // void destructor() override;
    };
}