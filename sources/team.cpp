#include "Team.hpp"
using namespace ariel;

Team::Team(Character *teamLeader)
    : teamLeader(teamLeader)
{
    this->add(teamLeader);
}

void Team::add(Character *character)
{
}

void Team::attack(Team *enemyTeam)
{
}

int Team::stillAlive()
{
    return 0;
}

void Team::print()
{
    cout << "needs to be implemented" << endl;
}

void Team::destructor()
{
}

void Team::setNewLeader()
{
}

Character *Team::closestVictimToLeader(Team *enemyTeam)
{
    Character *victim = nullptr;
    return victim;
}

bool Team::isNinja(Character *teamMember)
{
    return false;
}

Character *Team::getTeamLeader()
{
    return teamLeader;
}
