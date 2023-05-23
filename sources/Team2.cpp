#include "Team2.hpp"
using namespace ariel;

Team2::Team2(Character *teamLeader)
    : Team(teamLeader)
{
}

void Team2::print()
{
    vector<Character *> &members = this->getTeamMembers();
    for (auto &member : members)
    {
        cout << member->print() << endl;
    }
}

void Team2::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
    {
        throw invalid_argument("Enemy is nullptr");
    }
    if (this == enemyTeam)
    {
        throw runtime_error("Can't attack yourself");
    }
    if (enemyTeam->stillAlive() == 0)
    {
        throw runtime_error("Can't attack dead team");
    }
    if(stillAlive() == 0){
        throw runtime_error("Can't attack when team is dead");
    }
    
    // get vector
    vector<Character *> &members = getTeamMembers();
    Character *victim = closestVictimToLeader(enemyTeam);
    for (auto &member : members)
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }

        if (!getTeamLeader()->isAlive())
        {
            closestToLeader();
        }
        if (!victim->isAlive())
        {
            victim = closestVictimToLeader(enemyTeam);
        }
        if (dynamic_cast<Cowboy *>(member))
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            if (cowboy->isAlive())
            {
                cowboy->shoot(victim);
            }
        }
        if (dynamic_cast<Ninja *>(member))
        {
            Ninja *ninja = dynamic_cast<Ninja *>(member);
            if (ninja->isAlive())
            {
                if (ninja->distance(victim) < 1)
                {
                    ninja->slash(victim);
                }
                else
                {
                    ninja->move(victim);
                }
            }
        }
         if (!getTeamLeader()->isAlive())
        {
            closestToLeader();
        }

    }
}

// void Team2::destructor()
// {
//     vector<Character *> &members = this->getTeamMembers();
//     for (auto &member : members)
//     {
//         delete member;
//     }
//     members.clear();
// }
