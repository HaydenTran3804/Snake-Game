#include<bits/stdc++.h>
using namespace std;
#include "Snake_Food.h"

Food :: Food(int snake_y,int snake_x){

	do{
		srand(time(NULL));
        x = rand() % 48 + 1;
        y = rand() % 23 + 1;
    } while(x == snake_x && y == snake_y);
    }

void Food :: generate_pos(Map &mapp){
	do{
		srand(time(NULL));
        x = rand() % 48 + 1;
        y = rand() % 23 + 1;
    } while(mapp.check_food(y,x));
    }
		
			
int Food :: get_x(){
	return x;
}
int Food :: get_y(){
	return y;
}