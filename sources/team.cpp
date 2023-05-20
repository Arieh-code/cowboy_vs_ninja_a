#include "Team.hpp"
using namespace ariel;

Team::Team(Character *teamLeader)
    : teamLeader(teamLeader), teamMembers()
{
    this->add(teamLeader);
}

Team::~Team()
{
}

void Team::add(Character *character)
{
    if (!character)
    {
        throw runtime_error("Invalid character pointer");
    }
    teamMembers.push_back(character);
}

void Team::attack(Team *enemyTeam)
{
    // check leader is alive
    if (!teamLeader->isAlive())
    {
        closestToLeader();
    }

    // choose a victim to attack
    Character *victim = closestVictimToLeader(enemyTeam);

    // check team has people alive and enemy team has people alive

    // attack the chosen victim
    for (auto &member : teamMembers)
    {
        if (!victim->isAlive())
        {
            victim = closestVictimToLeader(enemyTeam);
        }
        else if (dynamic_cast<Cowboy *>(member))
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            cowboy->shoot(victim);
        }
    }
    for (auto &member : teamMembers)
    {
        if (!victim->isAlive())
        {
            victim = closestVictimToLeader(enemyTeam);
        }
        else if (dynamic_cast<Ninja *>(member))
        {
            Ninja *ninja = dynamic_cast<Ninja *>(member);
            ninja->slash(victim);
        }
    }
}

int Team::stillAlive()
{
    int alive = 0;
    for (auto &member : teamMembers)
    {
        if (member->isAlive())
        {
            alive += 1;
        }
    }

    return alive;
}

void Team::print()
{
    for (auto &member : teamMembers)
    {
        if (dynamic_cast<Cowboy *>(member))
        {
            cout << member->print() << endl;
        }
    }
    for (auto &member : teamMembers)
    {
        if (dynamic_cast<Ninja *>(member))
            cout << member->print() << endl;
    }
}

void Team::destructor()
{
    for (auto &member : teamMembers)
    {
        if (dynamic_cast<Cowboy *>(member))
            delete member;
    }
    for (auto &member : teamMembers)
    {
        if (dynamic_cast<Ninja *>(member))
            delete member;
    }
    teamMembers.clear();
}

void Team::setNewLeader(Character *character)
{
    teamLeader = character;
}

Character *Team::closestVictimToLeader(Team *enemyTeam)
{
    double minDistance = std::numeric_limits<double>::max();
    Character *victim = nullptr;
    for (auto &member : enemyTeam->teamMembers)
    {
        if (member->distance(teamLeader) < minDistance && member->isAlive())
        {
            minDistance = member->distance(teamLeader);
            victim = member;
        }
    }
    return victim;
}

void Team::closestToLeader()
{
    double minDistance = std::numeric_limits<double>::max();
    for (auto &member : teamMembers)
    {
        if (teamLeader->distance(member) < minDistance && member->isAlive())
        {
            minDistance = teamLeader->distance(member);
            this->setNewLeader(member);
        }
    }
}

Character *Team::getTeamLeader()
{
    return teamLeader;
}



