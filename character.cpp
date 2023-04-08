#include <iostream>
#include "character.h"
using namespace std;

Character::Character(){
    name = "default";
    offset = "0";
}

Character::Character(string n, string o){
    name = n;
    offset = o;
}

string Character::get_name(){
    return name;
}

string Character::get_offset(){
    return offset;
}