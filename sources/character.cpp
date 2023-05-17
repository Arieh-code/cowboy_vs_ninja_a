#include "character.hpp"

using namespace ariel;

Character::Character(Point position, int hits, string name)
    : position(position), hits(hits), name(name)
    {}

bool Character::isAlive(){
    return 0;
}

double Character::distance(Character *other){
    return 0.0;
}

void Character::hit(int points){

}

string Character::print(){
    return "";
}

string Character::getName(){
    return name;
}

Point Character::getLocation(){
    return position;
}

int Character::getHits(){
    return hits;
}

void Character::setHits(int amount){
    this->hits = amount;
}

void Character::setPosition(Point position){
    this->position = position;
}

const std::type_info& Character::getType() const{
    return typeid(Character);
}