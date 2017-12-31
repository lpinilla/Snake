#include <cxxtest/TestSuite.h>
#include <stdlib.h>
#include <vector>
#include "Snake.h"

  class MyTestSuite : public CxxTest::TestSuite
  {

  public:

    std::vector<SnakePart *> snake;

    void testSnakeCreation(){
        init();
        TS_ASSERT_EQUALS(snake.size() , 3);
    }

    void init(){
      createSnake();
    }

  

  };
