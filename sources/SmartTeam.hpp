#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Team.hpp"
#include <limits>
using namespace std;

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *);
        void attack(Team *enemyTeam) override;
        vector<int> distanceMatrix(Team * enemyTeam);
    };
}