#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

pTile board[MAPSIDE][MAPSIDE];

void createMap(){
    for(int i = 0; i < MAPSIDE; i++){
        for(int j = 0; j < MAPSIDE; j++){
            board[i][j] = (pTile) malloc(sizeof(tTile));
            board[i][j]->x = i;
            board[i][j]->y = j;
            board[i][j]->dir = 0; //HARDCODED 'NONE'
        }
    }
}

//int main(){} //just to compile
