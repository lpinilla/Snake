#include <stdio.h>
#include "Map.h"
#include "Snake.h"

std::vector<SnakePart *> snake; //shnek
Directions dir = NONE;
pTile headInitPos, bodyInitPos, tailInitPos;

int initialSnakeSize = 3;
bool bitten;

SnakePart::SnakePart(int x1, int y1){
    x = x1;
    y = y1;
}

void Head::assignDirection(Directions nDir){
	board[this->x][this->y]->dir = nDir;
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

bool move(int foodX, int foodY){
	Head * h = (Head *) snake.front();
	Directions prev = board[h->x][h->y]->dir;
	Tail * t = (Tail *) snake.back();
	int lastX = t->x, lastY = t->y;
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
		part->x = (part->x == 0)? MAPSIDE - 1 : part->x;
		part->y = (part->y == 0)? MAPSIDE - 1 : part->y;
		part->y %= MAPSIDE;
		part->x %= MAPSIDE;
	}
	if(board[h->x][h->y]->dir != NONE){
		bitten = true;
	}else{		
		h->assignDirection(prev);	
		board[lastX][lastY]->dir = NONE;	
		if(h->x == foodX && h->y == foodY){
			moveHead(h, prev);
			h->assignDirection(prev);	
			return true;
		}		
		return false;
	}
	
}

void moveHead(Head * h, Directions curr){
	auto it = snake.begin() + 1;
	snake.insert(it, (SnakePart *) new Body(h->x, h->y));
	switch(curr){
		case UP:			
			h->y+=1;
			break;
		case DOWN:
			h->y-=1;
			break;
		case LEFT:
			h->x-=1;
			break;
		case RIGHT:
			h->x+=1;
			break;
	}
}