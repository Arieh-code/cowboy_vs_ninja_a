#include "cowboy.hpp"
using namespace ariel;

Cowboy::Cowboy(string name, Point position)
    : Character(position, 110, name) , number_of_bullets(6)
    {}

int Cowboy::get_number_of_bullets(){
    return number_of_bullets;
}

void Cowboy::set_number_of_bullets(int bullets){
    this->number_of_bullets = bullets;
}

void Cowboy::shoot(Character *enemy){

}

bool Cowboy::has_bullets(){
    return 1;
}

void Cowboy::reload(){

}

void Cowboy::print(){
    cout << "needs to be implemented" << endl;
}

const std::type_info& Cowboy::getType() const{
    return typeid(Cowboy);
}