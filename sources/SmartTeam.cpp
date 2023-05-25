#include "SmartTeam.hpp"
using namespace ariel;

SmartTeam::SmartTeam(Character *teamLeader)
    : Team(teamLeader)
{
}

void SmartTeam::attack(Team *enemyTeam)
{
}

vector<int> SmartTeam::distanceMatrix(Team *enemyTeam)
{
    vector<vector<int>> matrix(10, vector<int>(10, 0));
    vector<Character *> &members = getTeamMembers();
    vector<Character *> &enemyMembers = enemyTeam->getTeamMembers();
    int out_counter = 0;
    for (auto &member : members)
    {
        int in_counter = 0;
        for (auto &enemy : enemyMembers)
        {
            if (out_counter == in_counter)
            {
                matrix[out_counter][in_counter++] = numeric_limits<int>::max();
            }
            else{
                matrix[out_counter][in_counter++] = member->distance(enemy);
            }
            
        }
        out_counter++;
    }

}
