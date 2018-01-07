#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define MAPSIDE 20


enum Directions {NONE = 0, UP, DOWN, LEFT, RIGHT};

void createMap();

typedef struct tile{ //weight: 24 bits
    int x, y;
    Directions dir;
}tTile;

typedef tTile * pTile;

extern pTile board[MAPSIDE][MAPSIDE];


#endif
