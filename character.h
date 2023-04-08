#include <iostream>
#include "data.h"
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character : public Data{
    private:
        string name;
        string offset;
    public:
        Character();
        Character(string n, string o);
        string get_name();
        string get_offset();
};

#endif