#include <Windows.h>
#include <iostream>
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "List.h"
#include "menu.h"
#include "Checkers.h"
using namespace std;

int main() {
	int idx = 0;
	int num_heroes, num_evils;
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	list<Person*> light_warriors;
	list<Person*> dark_warriors;
	cout << "Введите количество героев" << "\n";
	num_heroes = heroes_num();
	choose_light_person(light_warriors, num_heroes);
	cout << "Введите количество злодеев" << "\n";
	num_evils = heroes_num();
	choose_dark_person(dark_warriors, num_evils);
	while (dark_warriors.size() != 0 && light_warriors.size() != 0) {
		dark_persons_step(dark_warriors, light_warriors);
		light_persons_step(dark_warriors, light_warriors);
	}
	return 0;
} 