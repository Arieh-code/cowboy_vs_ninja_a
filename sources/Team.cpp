#include "Team.hpp"
using namespace ariel;

Team::Team(Character *teamLeader)
    : teamMembers()
{
    if (teamLeader == nullptr)
    {
        throw invalid_argument("nullptr");
    }
    if (!teamLeader->isAlive())
    {
        throw invalid_argument("leader must be alive");
    }
    if (teamLeader->getInTeam())
    {
        throw runtime_error("Leader is in a team already");
    }
    else
    {
        this->teamLeader = teamLeader;
        this->teamLeader->setInTeam(true);
        teamMembers.push_back(teamLeader);
    }
}

Team::~Team()
{
    for (auto &member : teamMembers)
    {
        delete member;
    }
    this->teamMembers.clear();
}

void Team::add(Character *character)
{
    if (!character)
    {
        throw runtime_error("Invalid character pointer");
    }
    if (teamMembers.size() == 10)
    {
        throw runtime_error("Team too big");
    }
    if (!character->isAlive())
    {
        throw runtime_error("Member must be alive");
    }
    if (character->getInTeam())
    {
        throw runtime_error("character already in team");
    }
    teamMembers.push_back(character);
    character->setInTeam(true);
}

void Team::attack(Team *enemyTeam)
{ // check leader is alive

    if (enemyTeam == nullptr)
    {
        throw invalid_argument("Enemy is nullPrt");
    }
    if (enemyTeam == this)
    {
        throw runtime_error("Can't attack yourself");
    }
    if (enemyTeam->stillAlive() == 0)
    {
        throw runtime_error("Can't attack dead team");
    }
    if (stillAlive() == 0)
    {
        throw runtime_error("Can't attack while team is dead");
    }

    // choose a victim to attack
    Character *victim = closestVictimToLeader(enemyTeam);

    // attack the chosen victim
    for (auto &member : teamMembers)
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }
        if (!teamLeader->isAlive())
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
    }
    for (auto &member : teamMembers)
    {
        if (enemyTeam->stillAlive() == 0)
        {
            return;
        }
        if (!teamLeader->isAlive())
        {
            closestToLeader();
        }
        if (!victim->isAlive())
        {
            victim = closestVictimToLeader(enemyTeam);
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

// void Team::destructor()
// {
//     for (auto &member : teamMembers)
//     {
//         if (dynamic_cast<Cowboy *>(member))
//             delete member;
//     }
//     for (auto &member : teamMembers)
//     {
//         if (dynamic_cast<Ninja *>(member))
//             delete member;
//     }
//     teamMembers.clear();
// }

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
        if (teamLeader->distance(member) < minDistance && member->isAlive())
        {
            minDistance = teamLeader->distance(member);
            victim = member;
        }
    }
    return victim;
}

void Team::closestToLeader()
{
    double minDistance = std::numeric_limits<double>::max();
    Character *temp = nullptr;
    for (auto &member : teamMembers)
    {
        if (member == teamLeader)
        {
            continue;
        }
        if (teamLeader->distance(member) < minDistance && member->isAlive())
        {
            minDistance = teamLeader->distance(member);
            temp = member;
        }
    }
    this->setNewLeader(temp);
}

Character *Team::getTeamLeader()
{
    return teamLeader;
}

vector<Character *> &Team::getTeamMembers()
{
    return teamMembers;
}
