#include "draw.h"
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "menu.h"
#include "Motion.h"
#include <Windows.h>
#include <iostream>
using namespace std;

#define underline "\033[4m"
#define no_underline "\033[0m"
GLint Width = 600, Height = 600;

const int R = 30; // радиус окружности и круга
const int N = 600;



void hello() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(2 * Width / 6 + 25, 3 * Height / 4); //позиция текста
	string s = "GAME OF THE YEAR";
	for (int i = 0; i < s.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);

	glRasterPos2i(2 * Width / 6 + 25, 3 * Height / 4); //позиция текста
	s = "____ __ ___ ____";
	for (int i = 0; i < s.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);

	glRasterPos2i(Width / 6, 2 * Height / 4); //позиция текста
	s = "~Nikita~ ~Motya~";
	for (int i = 0; i < s.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);


	glRasterPos2i(3.5 * Width / 6, 2 * Height / 4); //позиция текста
	s = "~Sevas~ ~Lubas~";
	for (int i = 0; i < s.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);

	glRasterPos2i(3 * Width / 6 - 25, Height / 4); //позиция текста
	s = "START";
	for (int i = 0; i < s.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);

	int R = 20; // радиус окружности и круга
	int N = 600;
	for (int j = 1; j <= N; j++) {
		glVertex2f(Width / 2 + R * cos(2 * 3.14 / N * j), Height / 3 + 30 + R * sin(2 * 3.14 / N * j));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, Height, 0);
	glVertex3f(Width / 12, Height, 0);
	glVertex3f(Width / 12, Height, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(Width, 0, 0);
	glVertex3f(Width, Height, 0);
	glVertex3f(Width - Width / 12, Height, 0);
	glVertex3f(Width - Width / 12, Height, 0);
	glEnd();
	glutSwapBuffers();
	glFlush();
}

//функция перерисовки hp 
void changes_hp(Person& pers, int side, int del, int j) {
	double proc = pers.hp();
	proc /= pers.max_hp();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);//прямоугольник
	glVertex3f(side * Width / 6 - 2 * R, (2 * j + 1) * Height / del + 2 * R, 0);
	glVertex3f(side * Width / 6 - 2 * R, (2 * j + 1) * Height / del + 3 * R / 2, 0);
	glVertex3f(side * Width / 6 - 2 * R + 4 * R * proc, (2 * j + 1) * Height / del + 3 * R / 2, 0);
	glVertex3f(side * Width / 6 - 2 * R + 4 * R * proc, (2 * j + 1) * Height / del + 2 * R, 0);
	glEnd();
}

//прорисовка стороны
void draw_side(list<Person*>& persons, int side, int num_heroes) {
	int del = num_heroes * 2; //сколько делений квадрата у нас для определенного кол-ва героев

	for (int j = 0; j < num_heroes; j++) {
		int proc = persons.find_value(j)->hp();
		proc /= persons.find_value(j)->max_hp();
		glBegin(GL_TRIANGLE_FAN);
		if (side == 1)
			glColor3f(51.0f / 255.0f, 0.0f / 255.0f, 153.0f / 255.0f);//Blue
		else if (side == 5)
			glColor3f(255.0f / 255.0f, 51.0f / 255.0f, 51.0f / 255.0f);//Red
		for (int i = 1; i <= N; i++) {
			glVertex2f(side * Width / 6 + R * cos(2 * 3.14 / N * i), (2 * j + 1) * Height / del + R * sin(2 * 3.14 / N * i));
		}
		glEnd();

		changes_hp(*(persons.find_value(j)), side, del, j);

		glRasterPos2i(side * Width / 6 - 2 * R, (2 * j + 1) * Height / del + 2.5 * R); //позиция текста
		string s = persons.find_value(j)->name();
		for (int i = 0; i < s.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
		}

	}
	glColor3ub(255, 0, 0);
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void display() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	hello();
	system("pause");

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);


	list<Person*> light_warriors;
	list<Person*> dark_warriors;
	int num_heroes, num_evils;

	//Левая сторона
	cout << underline << "Введите количество героев:" << no_underline << "\n";
	num_heroes = heroes_num();
	choose_light_person(light_warriors, num_heroes);
	int side = 1; //или 5, если рисуем по правую сторону

	//рисуем левую сторону
	draw_side(light_warriors, side, light_warriors.size());

	//Правая сторона
	cout << underline << "Введите количество злодеев:" << no_underline << "\n";
	num_evils = heroes_num();
	choose_dark_person(dark_warriors, num_evils);
	side = 5; //или 1, если рисуем по левую сторону

	//рисуем правую сторону
	draw_side(dark_warriors, side, dark_warriors.size());

	glClear(GL_COLOR_BUFFER_BIT);
	//бой
	while (dark_warriors.size() != 0 && light_warriors.size() != 0) {

		SetColor(8, 0);
		cout << "Ход светлых сил!\n";
		SetColor(7, 0);
		if (light_warriors.size() == 0 || dark_warriors.size() == 0)
			break;
		light_persons_step(dark_warriors, light_warriors);
		if (dark_warriors.size() == 0 || light_warriors.size() == 0)
			break;
		glClear(GL_COLOR_BUFFER_BIT);
		draw_side(light_warriors, 1, light_warriors.size());
		draw_side(dark_warriors, 5, dark_warriors.size());

		SetColor(2, 0);
		cout << "Ход тёмных сил!\n";
		SetColor(7, 0);
		dark_persons_step(dark_warriors, light_warriors);
		if (dark_warriors.size() == 0 || light_warriors.size() == 0)
			break;
		glClear(GL_COLOR_BUFFER_BIT);
		draw_side(light_warriors, 1, light_warriors.size());
		draw_side(dark_warriors, 5, dark_warriors.size());

		glutSwapBuffers();
		glFlush();
	}
	if (dark_warriors.size() != 0) {
		//желтый цвет
		SetColor(6, 0);
		cout << "Победила команда любителей тёмного пива!";
		SetColor(7, 0);
	}
	else if (light_warriors.size() != 0) {
		//тёмнокрасный цвет
		SetColor(4, 0);
		cout << "Победила команда любителей светлого пива!";
		SetColor(7, 0);
	}

	glutSwapBuffers();
	glFlush();
}

void myinit() {
	glClearColor(184.0f / 255.0f, 213.0f / 255.0f, 238.0f / 255.0f, 1.0f);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600, 0.0, 600);
}

void SpecKeyboard(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT) glutHideWindow();
}