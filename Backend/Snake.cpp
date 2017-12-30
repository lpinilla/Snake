#include <stdio.h>
#include <vector>
#include <iostream>
//#include <stdlib.h>
#include "Map.h"
#include "Snake.h"

//extern pTile board; //TODO do it properly

std::vector<SnakePart *> snake;
int initialSnakeSize = 3;

SnakePart::SnakePart(int x1, int y1){
    x = x1;
    y = y1;
}


void createSnake(){
	snake.push_back((SnakePart *) new Head(0,0));
	snake.push_back((SnakePart *) new Body(0,0));
	snake.push_back((SnakePart *) new Tail(0,0));
}




int main(){
    std::cout << "init" << "\n";
    createSnake();    
    std::cout << snake.size() << "\n";
    printf("%d \n", snake.size() == initialSnakeSize);
} //just to compile
