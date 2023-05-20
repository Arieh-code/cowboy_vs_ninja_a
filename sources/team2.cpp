#include "team2.hpp"
using namespace ariel;

Team2::Team2(Character *teamLeader)
    : Team(teamLeader)
{
    this->add(teamLeader);
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
    if (!this->getTeamLeader()->isAlive())
    {
        this->closesToLeader();
    }
    // get vector
    vector<Character *> &members = this->getTeamMembers();
    Character *victim = this->closestVictimToLeader(enemyTeam);
    for (auto &member : members)
    {
        if (dynamic_cast<Cowboy *>(member))
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            cowboy->shoot(victim);
        }
        else if (dynamic_cast<Ninja *>(member))
        {
            Ninja *ninja = dynamic_cast<Ninja *>(member);
            ninja->slash(victim);
        }
        if (!victim->isAlive())
        {
            victim = this->closestVictimToLeader(enemyTeam);
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