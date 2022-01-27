#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"
#include <stdlib.h>
#include <string>
#include <cstring>


#define COLUMNS 40
#define ROWS 40
//how many frames the snake moves per second
#define FPS 10
#define MessageBox // remove if it shows errors

//point to variable that stores snake direction in game.cpp
extern short sDirection;
//boolean expression to end game
bool gameOver = false;
int score = 0;
//message box

void display_callback();
void reshape_callback(int, int);
void timer_callback(int);
void keyboard_callback(int, int, int);


void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLUMNS, ROWS);

}

int main(int argc, char** argv) {
    //initialise glut and display mode and window size
    glutInit(&argc, argv);
    //double buffer window
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(500, 500);
    glutCreateWindow("KENYAN SNAKE");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0, timer_callback, 0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();

    return 0;
}
//int index =0;
void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    //should show message box but idk how to do that on linux yet
    if (gameOver) {

        char _score[10];
        itoa(score, _score, 10);
        char text[50] = "Your score is: ";
        strcat(text, _score);
        MessageBox(NULL, text, "GAME OVER");
        exit(0);

    }



}
//used to set viewport
void reshape_callback(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}
void timer_callback(int) {
    //calls display function as soon as possible
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timer_callback, 0);
}
void keyboard_callback(int key, int, int) {
    //control snake moves
    switch (key)
    {
    case GLUT_KEY_UP:
        if (sDirection != DOWN)
            sDirection = UP;
        break;
    case GLUT_KEY_DOWN:
        if (sDirection != UP)
            sDirection = DOWN;
        break;
    case GLUT_KEY_RIGHT:
        if (sDirection != LEFT)
            sDirection = RIGHT;
        break;
    case GLUT_KEY_LEFT:
        if (sDirection != RIGHT)
            sDirection = LEFT;
        break;
    }
}
