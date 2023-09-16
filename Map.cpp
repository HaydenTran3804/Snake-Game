#include <bits/stdc++.h>
#include "Map.h"
using namespace std;

Map :: Map(){
	check_map[25][50] = ' ';
}
void Map :: set_map(int y,int x, char value ){
	check_map[y][x] = value;
}
bool Map :: check_snake(int y,int x){
	if(check_map[y][x] == ' '){
		check_map[y][x] = 'o';
		return true;
	}
	return false;
}
bool Map :: check_food(int y,int x){
	if(check_map[y][x] == ' '){
		check_map[y][x] = '*';
		return false;
	}
	return true;
}
bool Map :: check_lose(int y,int x){
	if(check_map[y][x] == '#' && check_map[y][x] == 'o'){
		return true;
	}
	return false;
}