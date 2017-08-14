  #include <cxxtest/TestSuite.h>
  #include <stdlib.h>
  #include "Snake.h"

  class MyTestSuite : public CxxTest::TestSuite
  {
  public:
      SnakePart * snake;
      /*void testAddition( void ) //Test Syntax
      {
          TS_ASSERT( 1 + 1 > 1 );
          TS_ASSERT_EQUALS( 1 + 1, 2 );
      }*/

      /*Tests to do:
        Snake Creation:
                        Creation of Head, Body and Tail;
                        Check if initialSize == 3;
      */

      void typeHeadTest(){
          initSnake();
          TS_ASSERT( Head* h = dynamic_cast<Head*>(snake));
      }

      void initialSnakeSizeTest(){
          initSnake();
          TS_ASSERT_EQUALS( ((Head *) snake)->snakeSize, 3);
      }

  private:

      void initSnake(){
          int expandArraySize = 4;
          int totalSnakeWeight;
          int baseSnakeWeight = sizeof(Head) + sizeof(Body) + sizeof(Tail);
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


  };
