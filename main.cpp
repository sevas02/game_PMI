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
#include "text_color.h"
#pragma comment (lib, "Winmm.lib")
#define underline "\033[4m"
#define no_underline "\033[0m"
#define Width  600
#define Height 600
using namespace std;

int main(int argc, char** argv) {
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game of the year");
	glutDisplayFunc(display);
	glutSpecialFunc(SpecKeyboard);
	myinit();
	glutMainLoop();
	return 0;
} 