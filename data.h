#include <iostream>
using namespace std;

#ifndef DATA_H
#define Data_H

class Data{
    private:
        string name;
        string offset;
        int length;
        int max_quantity;
    public:
        Data();
        Data(string n, string o, int l, int m);
        string get_name();
        string get_offset();
        int get_length();
        int get_max_quantity();
};

#endif