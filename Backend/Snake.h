#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED



class SnakePart{
    public:
        int x, y;
        //SnakePart * next;
        SnakePart(int x, int y);
        void move();
};

extern std::vector<SnakePart *> snake;

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
