#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "game.h"

//#define COLUMNS 40
//#define ROWS 40
//#define FPS 10


int gridX, gridY;
//variables to keep track of snake position
int posX[60] = { 20,20,20,20, 20 }, posY[60] = { 20,19,18,16,16 }; //arrays for position of the snake
int snake_length = 5;
//variable to store current direction the snake is moving
short sDirection = RIGHT;
bool food = true;
int foodX, foodY;
bool food1 = true;
int food1x,foodly;
extern bool gameOver;
extern int score;
//function to initialize grid
void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}
void unit(int, int);
//function to draw grid

void drawGrid() {

    for (int x = 0; x < gridX; x++) {
        for (int y = 0; y < gridY; ++y) {
            unit(x, y);
        }
    }

}
void unit(int x, int y) {

    //for the borders of the snake
    if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
    }
    else {
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
    }

    glLineWidth(1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}
//function for the food
void drawFood() {

    if (food)
        random(foodX, foodY);
    food = false;
    glRectf(foodX, foodY, foodX + 1, foodY + 1);
    glColor3f(0.0, 0.5, 0.5); //color of food = green
    
  if (food1)
        random1(foodx, foody);
    food1= false;
    glRectf(food1x, food1y, food1x + 1, food1y + 1);
    glColor3f(0.6, 0.8, 1.0);  
    
}

void random1(int& i, int& j){
    int_max1X= gridX - 2;
    int_max1y= gridY - 2;
    int_min1 =1;
    srand(time(NULL));
    i=_min1 + rand() % (_max1X - _min1);
     i=_min1 + rand() % (_max1X - _min1);
}
void random(int& x, int& y) {
    int _maxX = gridX - 2;
    int _maxY = gridY - 2;
    int _min = 1;
    srand(time(NULL));
    x = _min + rand() % (_maxX - _min);
    y = _min + rand() & (_maxY - _min);
}


void drawSnake() {

    for (int i = snake_length - 1; i > 0; i--) {
        posX[i] = posX[i - 1];
        posY[i] = posY[i - 1];
    }
    if (sDirection == UP)
        posY[0]++;
    else if (sDirection == DOWN)
        posY[0]--;
    else if (sDirection == RIGHT)
        posX[0]++;
    else if (sDirection == LEFT)
        posX[0]--;
    for (int i = 0; i < snake_length; i++) {
        if (i == 0)
            glColor3f(0.0, 0.0, 1.0); //color of snake = blue
        else
            glColor3f(1.0, 0.0, 0.0);
        glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
    }


    if (posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1)
        gameOver = true;
    if (posX[0] == foodX && posY[0] == foodY) {


        score++;
        snake_length++;
        if (snake_length > MAX)
            snake_length = MAX;
        food = true;

    }
    for (int j = 1; j < snake_length; j++)
    {
        if (posX[j] == posX[0] && posY[j] == posY[0])
            gameOver = true;
    }




}
