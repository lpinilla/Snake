#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include <iostream> //to test
#include "../Backend/Map.h"
#include "../Backend/Snake.h"

#define FPS 10

typedef struct color{
	float r,g,b;
}tColor;

void renderScene();
void changeSize(int w, int h);
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void drawTile(int x, int y, tColor color, float width);
tColor createColor(float r, float g, float b);
void randomFoodPos(int &x, int &y);
void timer(int);

tColor red, green, blue, white, nColor;
int foodX, foodY;
bool food = true;
Directions lastDir = UP;

void createBasicColors(){
	red = createColor(1.0f,0.0f,0.0f);
	green = createColor(0.0f, 1.0f, 0.0f);
	blue = createColor(0.0f, 0.0f, 1.0f);
	white = createColor(1.0f, 1.0f, 1.0f);
}

int main(int argc, char ** argv){
	createBasicColors();
	preSetGame();
	//init glut & create window
	glutInit(&argc, argv);
	glutInitWindowPosition(-1,-1);
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Shnek");

	glutTimerFunc(1000, timer, 0);
	//register callback
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	//idle func registration
	glutIdleFunc(renderScene);
	
	//keyboard
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	//enter glub event processing cycle	
	glutMainLoop();

	return 1;
}

void drawBoard(){
	/*nColor = createColor(1.0,1.0,0.0);
	tColor orange = createColor(1.0,0.5,0.0);
	tColor cyan = createColor(0.0,1.0,1.0);
	tColor purple = createColor(1.0,0.0,1.0);*/
	for(int i = 0; i < MAPSIDE ; i++){
		for(int j = 0; j < MAPSIDE; j++){
			if(i == 0 || i == MAPSIDE-1 ||
				j == 0 || j == MAPSIDE-1){
					drawTile(i, j, red, 3.0f);
			}else{
				drawTile(i,j, white, 1.0f);
			}
			/*if(board[i][j]->dir == UP){
				drawTile(i,j, nColor, 1.0f);
			}
			if(board[i][j]->dir == RIGHT){
				drawTile(i,j, orange, 1.0f);
			}
			if(board[i][j]->dir == DOWN){
				drawTile(i,j, cyan, 1.0f);
			}
			if(board[i][j]->dir == LEFT){
				drawTile(i,j, purple, 1.0f);
			}*/
		}
	}
}

void drawSnake(){	
	for(SnakePart * part : snake){
		drawTile(part->x, part->y, green, 3.0f);
		std::cout << part->y;
	}
	std::cout << "end\n";
}

void drawFood(){
	nColor = createColor(1.0, 0.0, 1.0); //pink
	if(food){
		randomFoodPos(foodX, foodY);
	}
	food = false;
	drawTile(foodX, foodY, nColor, 2.0f);
}

void drawTile(int x, int y, tColor color, float width){
	glColor3f(color.r, color.g, color.b);
	glLineWidth(width);
	glBegin(GL_LINE_LOOP); //otro estilo con GL_QUADS
		glVertex2f(x,y);
		glVertex2f(x+1,y);
		glVertex2f(x+1,y+1);
		glVertex2f(x,y +1);
	glEnd();
}


void renderScene(){	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity(); //reset transformations
	drawBoard();
	drawSnake();
	drawFood();
	
	glutSwapBuffers();
}

void changeSize(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho( 0.0, (float) MAPSIDE, 0.0, (float) MAPSIDE, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y){
	if(key == 27){
		exit(0);
	}
	if(key == 109){
		move();
	}
}

void processSpecialKeys(int key, int x, int y){
	Head * h = (Head *) snake.at(0);
	switch(key){
		case GLUT_KEY_UP:
			if(lastDir != DOWN){
				h->assignDirection(UP);
				lastDir = UP;
			}
			break;
		case GLUT_KEY_RIGHT:
			if(lastDir != LEFT){
				h->assignDirection(RIGHT);
				lastDir = RIGHT;
			}
			break;
		case GLUT_KEY_DOWN:
			if(lastDir != UP){
				h->assignDirection(DOWN);
				lastDir = DOWN;
			}
			break;
		case GLUT_KEY_LEFT:
			if(lastDir != RIGHT){
				h->assignDirection(LEFT);
				lastDir = LEFT;
			}
			break;
	}
}

tColor createColor(float r, float g, float b){
	tColor ret;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	return ret;
}

void randomFoodPos(int &x, int &y){
  int _maxX = MAPSIDE -2;
  int _maxY = MAPSIDE-2;
  int _min = 1;
  srand(time(NULL));
  x = _min + rand() % (_maxX -_min);
  y = _min + rand() % (_maxY -_min);
}

void timer(int){
	move();
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timer, 0);
}

