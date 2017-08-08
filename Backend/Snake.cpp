#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "Snake.h"

//extern pTile board; //TODO
int baseSnakeWeight;
int expandArraySize = 5;
int totalSnakeWeight = 0;


class SnakePart{
    public:
        int x, y;
        SnakePart * next;
        SnakePart(){
            x = y = 0; //ineficiente si lo voy a pisar
            next = NULL; //necesario?
        }
};

SnakePart * snake;

class Body : public SnakePart{
};

class Tail : public SnakePart{

    public:
        void clearTileDir(){
            //TODO needs a reference to the board
            //board[this->x][this->y] = 0;
        }
};

class Head : public SnakePart{
    public:
        int snakeSize;
        Head(){
            snakeSize = 0;
        }

        void addBody(){
            SnakePart aux;
            while(this->next != NULL){ //grab the tail
                aux = *(this->next);
            }
            if(snakeSize % expandArraySize == 0){ //need to expand
                snake = (SnakePart *) realloc(snake, totalSnakeWeight + expandArraySize * sizeof(Body));
            }
            pushTail(aux);
            *(snake + sizeof(Head) + (snakeSize + 1) * sizeof(Body)) = Body();
            snakeSize++;
        }

    private:
        void pushTail(SnakePart aux){ //TODO

        }
};




void createSnake(){
    baseSnakeWeight = sizeof(Head) + sizeof(Body) + sizeof(Tail);
    snake = (SnakePart *) malloc(totalSnakeWeight = (baseSnakeWeight + expandArraySize * sizeof(Body)));
    //manually creating the parts of the shnek
    *snake = Head();
    *(snake + sizeof(Head)) =  Body();
    *(snake + sizeof(Head) + sizeof(Body)) = Tail();
    //assigning the nexts
    (snake)->next = (snake + sizeof(Head));
    (snake + sizeof(Head))->next = (snake + sizeof(Head) + sizeof(Body));
    (snake + sizeof(Head) + sizeof(Body))->next = NULL;
    //add 3 to the snake size (base size)
    ((Head *) snake)->snakeSize += 3;
}

int main(){} //just to compile
