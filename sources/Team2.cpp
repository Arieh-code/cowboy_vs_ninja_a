#include "Team2.hpp"
using namespace ariel;

Team2::Team2(Character *teamLeader)
    : Team(teamLeader)
{

    // this->add(teamLeader);
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
    if (enemyTeam->stillAlive() == 0)
    {
        throw runtime_error("Can't attack dead team");
    }
    if (this == enemyTeam)
    {
        throw runtime_error("Can't attack yourself");
    }

    // get vector
    vector<Character *> &members = this->getTeamMembers();
    Character *victim = this->closestVictimToLeader(enemyTeam);
    for (auto &member : members)
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }

        if (!this->getTeamLeader()->isAlive())
        {
            this->closestToLeader();
        }
        if (!victim->isAlive())
        {
            victim = this->closestVictimToLeader(enemyTeam);
        }
        if (dynamic_cast<Cowboy *>(member))
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            if (cowboy->isAlive())
            {
                cowboy->shoot(victim);
            }
        }
        else if (dynamic_cast<Ninja *>(member))
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
    }
}

void Team2::destructor()
{
    vector<Character *> &members = this->getTeamMembers();
    for (auto &member : members)
    {
        delete member;
    }
    members.clear();
}
