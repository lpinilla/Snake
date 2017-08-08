#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

#define MAPSIDE 10

typedef struct tile{ //weight: 24 bits
    int x, y, dir;
}tTile;

typedef tTile * pTile;

pTile board[MAPSIDE * MAPSIDE];

void createMap(){
    for(int i = 0, t= 0; i < MAPSIDE; i++){
        for(int j = 0; j < MAPSIDE; j++, t++){
            board[t] = (tTile *) malloc(sizeof(tTile));
            board[t]->x = i;
            board[t]->y = j;
            board[t]->dir = NONE;
        }
    }
}

void operation(int dir){
}

//int main(){} //just to compile
