#include "Team.hpp"
using namespace ariel;

Team::Team(Character *teamLeader)
    : teamLeader(teamLeader), cowboys(), ninjas()
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
    // Cowboy *cowboyPtr = dynamic_cast<Cowboy *>(character);
//     if (cowboyPtr)
//     {
//         cowboys.push_back(cowboyPtr);
//     }
//     else
//     {
//         Ninja *ninjaPtr = dynamic_cast<Ninja *>(character);
//         if (ninjaPtr)
//         {
//             ninjas.push_back(ninjaPtr);
//         }
//         else
//         {
//             throw runtime_error("character is not a ninja or a cowboy");
//         }
//     }
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
    while (stillAlive() > 0 && enemyTeam->stillAlive() > 0)
    {
        // attack the chosen victim
        for (auto &member : teamMembers)
        {
            if (!victim->isAlive())
            {
                victim = closestVictimToLeader(enemyTeam);
            }
            else if(dynamic_cast<Cowboy *>(member))
            {
                member->shoot(victim);
            }
        }
        for (auto &member : teamMembers)
        {
            if (!victim->isAlive())
            {
                victim = closestVictimToLeader(enemyTeam);
            }
            else if(dynamic_cast<Ninja *>(member))
            {
                member->slash(victim);
            }
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
        if(dynamic_cast<Cowboy *>(member))
        member->print();
    }
    for (auto &member : teamMembers)
    {
        if(dynamic_cast<Ninja *>(member))
        member->print();
    }
}

void Team::destructor()
{
    for (auto &member : teamMembers)
    {
        if(dynamic_cast<Cowboy *>(member))
        delete member;
    }
    for (auto &member : teamMembers)
    {
        if(dynamic_cast<Ninja *>(member))
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
