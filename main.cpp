#include <Windows.h>
#include <iostream>
#include <mmsystem.h>
#include "resource.h"
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "List.h"
#include "menu.h"
#include "Checkers.h"
#include "draw.h"
#pragma comment (lib, "Winmm.lib")
#define underline "\033[4m"
#define no_underline "\033[0m"
#define Width  1000
#define Height 1000
using namespace std;


int main(int argc, char** argv) {
	/*glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game of the year");
	glutDisplayFunc(display);
	glutSpecialFunc(SpecKeyboard);
	glutTimerFunc(33, TimerMove, 1);
	myinit();
	glutMainLoop();*/

	int idx = 0;
	int num_heroes, num_evils;
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	list<Person*> light_warriors;
	list<Person*> dark_warriors;
	cout << underline << "Введите количество героев:" << no_underline << "\n";
	num_heroes = heroes_num();
	choose_light_person(light_warriors, num_heroes);
	cout << underline << "Введите количество злодеев:" << no_underline << "\n";
	num_evils = heroes_num();
	choose_dark_person(dark_warriors, num_evils);
	while (dark_warriors.size() != 0 && light_warriors.size() != 0) {
		dark_persons_step(dark_warriors, light_warriors);
		light_persons_step(dark_warriors, light_warriors);
	}

	if (dark_warriors.size() != 0) {
		//желтый цвет
		SetColor(6, 0);
		cout << "Победила команда любителей тёмного пива";
		SetColor(7, 0);
	}
	else {
		//тёмнокрасный цвет
		SetColor(4, 0);
		cout << "Победила команда любителей светлого пива";
		SetColor(7, 0);
	}
	
	return 0;
} 