#ifndef Map_H
#define Map_H
#include<bits/stdc++.h>
using namespace std;
class Map{
	private:
		char check_map[25][50];
	public:
		Map();
		void set_map(int y,int x, char value);
		bool check_snake(int y,int x);
		bool check_food(int y,int x);
		bool check_lose(int y,int x);
};
#endif