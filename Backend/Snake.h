#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include <vector>

enum Directions {NONE = 0, UP, DOWN, LEFT, RIGHT};

class SnakePart{
    public:
        int x, y;
        SnakePart(int x, int y);
        void move();
};

extern std::vector<SnakePart *> snake;

void createSnake();
void setInitialDirections();
void setInitTiles(int x1, int y1, Directions dir, pTile tile);
void preSetGame();
void move();

class Body : public SnakePart{
    public:
        Body(int x, int y) : SnakePart(x, y) {} 
};

class Tail : public SnakePart{
    public:
        Tail(int x, int y) : SnakePart(x, y) {}
        void pushTail(); //void or SnakePart?
        void clearTileDir();
};

class Head : public SnakePart{
    public:
        Head(int x, int y) : SnakePart(x, y) {}
        int snakeSize;
        void eatFood();
        void assignDirection();
};



#endif
