#ifndef Snake_Food_H
#define Snake_Food_H
#include<bits/stdc++.h>
#include "Map.h"
using namespace std;

class Food{
    private:
    int x,y;
    public:
    Food(int snake_y,int snake_x);
    void generate_pos(Map &mapp);
    int get_x();
    int get_y();
};

#endif