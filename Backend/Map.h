#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define MAPSIDE 20

void createMap();

typedef struct tile{ //weight: 24 bits
    int x, y, dir;
}tTile;

typedef tTile * pTile;

extern pTile board[MAPSIDE][MAPSIDE];


#endif
