#include "SmartTeam.hpp"
using namespace ariel;

SmartTeam::SmartTeam(Character *teamLeader)
    : Team(teamLeader)
{this->add(teamLeader);}

void SmartTeam::add(Character * teamMember){

}

int SmartTeam::stillAlive(){
    return 0;
}

void SmartTeam::print(){
    cout << "needs to be implemented" << endl;
}

void SmartTeam::attack(Team *enemyTeam){

}

void SmartTeam::setNewLeader(){

}

void SmartTeam::destructor(){
    
}