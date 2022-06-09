#include "draw.h"
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "menu.h"
#include <Windows.h>
#include <iostream>
using namespace std;

#define underline "\033[4m"
#define no_underline "\033[0m"
GLint Width = 600, Height = 600;

const int R = 30; // радиус окружности и круга
const int N = 600;

//функция перерисовки hp 
void changes_hp(Person& pers, int side, int del, int j) {
	double proc = pers.hp();
	proc /= pers.max_hp();
	cout << proc << "   NAME   " << pers.name() << "\n";
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);//прямоугольник
	glVertex3f(side * Width / 6 - 2 * R, (2 * j + 1) * Height / del + 2 * R, 0);
	glVertex3f(side * Width / 6 - 2 * R, (2 * j + 1) * Height / del + 3 * R / 2, 0);
	glVertex3f(side * Width / 6 + 2 * R * proc, (2 * j + 1) * Height / del + 3 * R / 2, 0);
	glVertex3f(side * Width / 6 + 2 * R * proc, (2 * j + 1) * Height / del + 2 * R, 0);
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
		else
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
	glutSwapBuffers();
	glFlush();
}

void display() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	list<Person*> light_warriors;
	list<Person*> dark_warriors;
	int num_heroes, num_evils;

	Person pers;
	int proc = pers.hp();
	proc /= pers.max_hp();

	//Левая сторона
	cout << underline << "Введите количество героев:" << no_underline << "\n";
	num_heroes = heroes_num();
	choose_light_person(light_warriors, num_heroes);
	int side = 1; //или 5, если рисуем по правую сторону
	
	//рисуем левую сторону
	draw_side(light_warriors, side, num_heroes);

	//Правая сторона
	cout << underline << "Введите количество злодеев:" << no_underline << "\n";
	num_evils = heroes_num();
	choose_dark_person(dark_warriors, num_evils);
	side = 5; //или 1, если рисуем по левую сторону

	//рисуем правую сторону
	draw_side(dark_warriors, side, num_evils);


	//бой
	while (dark_warriors.size() != 0 && light_warriors.size() != 0) {
		SetColor(8, 0);
		cout << "Ход светлых сил!\n";
		SetColor(7, 0);
		light_persons_step(dark_warriors, light_warriors);
		choose_dark_person(dark_warriors, num_evils);
		SetColor(2, 0);
		cout << "Ход тёмных сил!\n";
		SetColor(7, 0);
		dark_persons_step(dark_warriors, light_warriors);
		choose_light_person(light_warriors, num_heroes);
		glutSwapBuffers();
		glFlush();
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

