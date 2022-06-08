#include "draw.h"
#include <iostream>

GLint Width = 1000, Height = 1000;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);


	int R = 20; // радиус окружности и круга
	int N = 500;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);//Black
	glVertex2f(Width/6, 100);
	for (int i = 1; i <= N; i++) {
		glVertex2f(Width / 6 + R*cos(2 * 3.14 / N * i),  100+ R*sin(2 * 3.14 / N * i));
	}
	glEnd();


	R = 20; // радиус окружности и круга
	N = 500;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);//Black
	glVertex2f(Width / 6, 250);
	for (int i = 1; i <= N; i++) {
		glVertex2f(Width / 6 + R * cos(2 * 3.14 / N * i),250 + R * sin(2 * 3.14 / N * i));
	}
	glEnd();


	R = 20; // радиус окружности и круга
	N = 500;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);//Black
	glVertex2f(Width / 6, 400);
	for (int i = 1; i <= N; i++) {
		glVertex2f(Width / 6 + R * cos(2 * 3.14 / N * i), 400 + R * sin(2 * 3.14 / N * i));
	}
	glEnd();



	//квадратики
	//glBegin(GL_QUADS);
	//glColor3f(0.0f, 0.0f, 0.0f);//Black
	//
	//glVertex2f(x, y + 100); //левый низ
	//glVertex2f(x + 100, y ); //левый верх
	//glVertex2f(x , y ); //правый верх
	//glVertex2f(x + 100, y + 100); //правый низ
	//		
	//glEnd();

	glutSwapBuffers();
	glFlush();
}

void myinit() {
	glClearColor(184.0f / 255.0f, 213.0f / 255.0f, 238.0f / 255.0f, 1.0f);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void SpecKeyboard(int key, int x, int y) {
	if (key ==  GLUT_KEY_RIGHT) glutHideWindow();
}

void TimerMove(int value) {
	glColor3ub(255, 0, 0);
	glutPostRedisplay();
	glutTimerFunc(33, TimerMove, 1);
}
