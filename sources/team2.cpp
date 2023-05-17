#include "team2.hpp"
using namespace ariel;


Team2::Team2(Character* teamLeader)
    : Team(teamLeader)
{this->add(teamLeader);}

void Team2::add(Character* teamMember){

}

int Team2::stillAlive() {
    return 0;
}

void Team2::print(){
    cout << "needs to be implemented" << endl;
}

void Team2::attack(Team* enemyTeam){

}

void Team2::setNewLeader() {

}

void Team2::destructor(){
    
}