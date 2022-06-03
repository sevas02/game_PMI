#include <Windows.h>
#include <iostream>
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "List.h"
#include "menu.h"
using namespace std;

int main() {
	int idx = 0;
	int num_heroes, num_evils;
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	list<Person*> light_warriors;
	list<Person*> dark_warriors;
	cout << "Введите количество героев" << "\n";
	cin >> num_heroes;
	choose_light_person(light_warriors, num_heroes);
	cout << "Введите количество злодеев" << "\n";
	cin >> num_evils;
	choose_dark_person(dark_warriors, num_evils);
	cout << "Хп первого героя:" << light_warriors.find_value(0)->hp()<< '\n';
	for (int i = 0; i < 3; i++) {
		idx = get_idx_dark(dark_warriors.find_value(i));
		if (idx == 1)
			dynamic_cast<Monster_base*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		else if (idx == 2)
			dynamic_cast<Monster_boss*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		else if (idx == 3)
			dynamic_cast<Monster_base_better*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
	}
	cout << "Хп первого героя:" << light_warriors.find_value(0)->hp() << '\n';
	return 0;
} 