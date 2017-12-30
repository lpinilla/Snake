  #include <cxxtest/TestSuite.h>
  #include <stdlib.h>
  #include "Snake.h"

  class MyTestSuite : public CxxTest::TestSuite
  {
  public:
      /*void testAddition( void ) //Test Syntax
      {
          TS_ASSERT( 1 + 1 > 1 );
          TS_ASSERT_EQUALS( 1 + 1, 2 );
      }*/

  void testSnakeCreation(){
      TS_ASSERT_EQUALS(snake.size() , 3);
  }

  

  };
