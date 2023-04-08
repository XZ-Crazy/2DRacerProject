#include <iostream>
#include "data.h"
using namespace std;

Data::Data(){
    name = "default";
    offset = "0";
    length = 1;
    max_quantity = 99;
}

Data::Data(string n, string o, int l, int m){
    name = n;
    offset = o;
    length = l;
    max_quantity = m;
}

string Data::get_name(){
    return name;
}

string Data::get_offset(){
    return offset;
}

int Data::get_length(){
    return length;
}

int Data::get_max_quantity(){
    return max_quantity;
}