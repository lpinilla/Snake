#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define DIM 5

void addBody();

class SnakePart{
    public:
        int x, y;
        SnakePart * next;
        SnakePart();
};

class Body : public SnakePart{
};

class Tail : public SnakePart{
    public:
        void clearTileDir();
};

class Head : public SnakePart{
    public:
        int snakeSize;
        Head();
        void addBody();

    private:
        void pushTail(SnakePart aux);
};

#endif
