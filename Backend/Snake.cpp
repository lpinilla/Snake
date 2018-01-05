#include <stdio.h>
#include <iostream>
#include "Map.h"
#include "Snake.h"

std::vector<SnakePart *> snake; //shnek
Directions dir = NONE;
pTile headInitPos, bodyInitPos, tailInitPos;

int initialSnakeSize = 3;

SnakePart::SnakePart(int x1, int y1){
    x = x1;
    y = y1;
}

void preSetGame(){
	createSnake();
	createMap();
	setInitialDirections();
}


void createSnake(){
	snake.push_back((SnakePart *) new Head(2,4));
	snake.push_back((SnakePart *) new Body(2,3));
	snake.push_back((SnakePart *) new Tail(2,2));
}

void setInitialDirections(){
	board[2][4]->dir = UP;
	board[2][3]->dir = UP;
	board[2][2]->dir = UP; //tail
}

void move(){
	for(SnakePart * part : snake){
		switch(board[part->x][part->y]->dir){
			case UP:
				part->y = part->y+1;
				break;
			case DOWN:
				part->y = part->y-1;
				break;
			case LEFT:
				part->x = part->x-1;
				break;
			case RIGHT:
				part->x = part->x+1;
				break;
			case NONE:
				break;			
		}
	}
}