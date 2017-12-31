#include <stdio.h>
#include <vector>
#include <iostream>
//#include <stdlib.h>
#include "Map.h"
#include "Snake.h"

//extern pTile board; //TODO do it properly

std::vector<SnakePart *> snake; //shnek
Directions dir = UP; //test hardcoded

int initialSnakeSize = 3;

SnakePart::SnakePart(int x1, int y1){
    x = x1;
    y = y1;
}


void createSnake(){
	snake.push_back((SnakePart *) new Head(0,2));
	snake.push_back((SnakePart *) new Body(0,1));
	snake.push_back((SnakePart *) new Tail(0,0));
}


int main(){
    createSnake();  
    //std::cout << dir << "\n";
} //just to see compile errors
