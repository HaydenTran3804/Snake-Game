#ifndef Snake_Snake_H
#define Snake_Snake_H
#include<bits/stdc++.h>
#include "Snake_Food.h"
#include "Map.h"
using namespace std;

class Snake{
    private:
    int x,y,old_x,old_y;
    deque<pair<int,int>> body;
    public:
    Snake();
    int get_x();
    int get_y();
    void move(char dir,Map mapp);
    bool find_body(int i,int j);
    void grow(Map &mapp,Food &food,char dir);
    deque<pair<int,int>> get_body();
};

#endif
