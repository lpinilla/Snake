#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include <vector>
#include "Map.h"


class SnakePart{
    public:
        int x, y;
        SnakePart(int x, int y);
};

extern std::vector<SnakePart *> snake;
extern bool bitten;



class Body : public SnakePart{
    public:
        Body(int x, int y) : SnakePart(x, y) {} 
};

class Tail : public SnakePart{
    public:
        Tail(int x, int y) : SnakePart(x, y) {}
        void pushTail(); //void or SnakePart?
};

class Head : public SnakePart{
    public:
        Head(int x, int y) : SnakePart(x, y) {}
        int snakeSize;
        void eatFood();
        void assignDirection(Directions nDir);
};

void createSnake();
void setInitialDirections();
void setInitTiles(int x1, int y1, Directions dir, pTile tile);
void preSetGame();
bool move(int foodX, int foodY);
bool hasFood(Head * h, Directions prev, int foodX, int foodY);
void moveHead(Head * h, Directions curr);



#endif
