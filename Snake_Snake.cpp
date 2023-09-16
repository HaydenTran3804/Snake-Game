#include<bits/stdc++.h>
using namespace std;
#include "Snake_Snake.h"
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
Snake :: Snake(int speed){
    srand(time(NULL));
    x = rand() % 48 + 1;
    y = rand() % 23 + 1;
    old_x = x;
    old_y = y;
    this->speed = speed;
    body.push_back({y,x});
}
int Snake :: get_x(){
    return x;
}
int Snake :: get_y(){
    return y;
}
void Snake :: move(char dir,Map mapp){
	pair<int,int> head = body.front();
    old_x = x;
    old_y = y;
    if(dir == 'w') {
    	y = head.first - speed;
    	if(y <= 0 || mapp.check_lose(y,x)){
    		cout << endl;
    		cout << "You lose" << endl << system("PAUSE");
		}
	}
    if(dir == 's'){
    	y = head.first + speed;
    	if(y >= 25 || mapp.check_lose(y,x)){
    		cout << endl;
    		cout << "You lose" << endl << system("PAUSE");
		}
    }
    if(dir == 'd'){
		x =  head.second + speed;
    	if(x >= 49 || mapp.check_lose(y,x)){
    		cout << endl;
    		cout << "You lose" << endl << system("PAUSE");
		}
	}
    if(dir == 'a'){
		x = head.second - speed;
		if(x <= 0 || mapp.check_lose(y,x)){
    		cout << endl;
    		cout << "You lose" << endl << system("PAUSE");
		}
    	
 }
 body.push_front({y,x});
    	body.pop_back();
}
bool Snake::find_body(int i,int j){
	deque<pair<int,int>> tmp = body;
	while(!tmp.empty()){
		if(tmp.front().first == i and tmp.front().second == j){
			return true;
		}
		tmp.pop_front();
	}
	return false;
}
void Snake :: grow(Map &mapp,Food &food, char dir){
	int sign = 0;
	if(y == food.get_y()){
		if(dir == 'a'){
			if(x <= food.get_x() && food.get_x() < old_x) sign = 1;
		}
		if(dir == 'd'){
			if(x >= food.get_x() && food.get_x() > old_x) sign = 1;
		}
}
	if(x == food.get_x()){
		if(dir == 's'){
			if(y >= food.get_y() && food.get_y() > old_y) sign = 1;
		}
		if(dir == 'w'){
			if(y <= food.get_y() && food.get_y() < old_y) sign = 1;
		}
}
	old_x = x;
	old_y = y;
	if(sign){
		food.generate_pos(mapp);
	pair<int,int> tail = body.back();
	for(int i=0;i<4;i++){
		int new_x = tail.second + dx[i];
		int new_y = tail.first + dy[i];
		if(mapp.check_snake(new_y,new_x)){
			body.push_back({new_y,new_x});
			break;
		}
	}
	}
}
deque<pair<int,int>> Snake :: get_body(){
	return body;
}
