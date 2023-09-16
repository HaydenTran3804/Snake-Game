#include <bits/stdc++.h>
#include "Snake_Food.cpp"
#include "Map.cpp"
#include "Snake_Snake.cpp"
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
Map mapp;

void board(Snake snake,Food food){
    for(int i=0;i<25;i++){
        cout << "\t\t\t\t";
        for(int j=0;j<50;j++){
        	char value = ' ';
            if (snake.find_body(i,j)){
            	value = 'o';
                cout << "o";
            }
            else if(i == food.get_y() && j == food.get_x()){
            	value = '*';
                cout << '*';
            } else if(i == 0 or i == 24 or j == 0 or j == 49){
            	value = '#';
                cout << "#";
            } else{
                cout<<" ";
            }
            mapp.set_map(i,j,value);
        }
        cout << endl;
    }
}

int main(){
	int score = 0;
	int speed = 1;
	Snake snake(speed);
	Food food(snake.get_y(),snake.get_x()); 
    char dir = 'h';
    while(true){
		board(snake,food);
		cout << "Score: "<< score;
		score = snake.get_body().size();
	if(kbhit()){
		switch(getch()){
			case 'w': if(dir != 's') dir = 'w';break;
			case 's': if(dir != 'w') dir = 's';break;
			case 'd': if(dir != 'a') dir = 'd';break;
			case 'a': if(dir != 'd') dir = 'a';break;
		}	
		snake.move(dir,mapp);
	
	} else {
		snake.move(dir,mapp);
	}
	snake.grow(mapp,food,dir); 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});

}                          	  
return 0;
    cout << endl << system("PAUSE");
}