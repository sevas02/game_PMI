#include <Windows.h>
#include <iostream>
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "List.h"
using namespace std;

int det_person(Person* hero) {
	if (typeid(*hero) == typeid(Monster_base))
		return 1;
	else if (typeid(*hero) == typeid(Monster_boss))
		return 2;
	else if (typeid(*hero) == typeid(Monster_base_better))
		return 3;
	else
		return -1;
}

int main() {
	int idx = 0;
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	list<Person*> light_warriors;
	list<Person*> dark_warriors;
	cout << "Наши герои: Маг Лучник Воин" << "\n";
	Wizard* mag = new Wizard();
	Archer* luk = new Archer();
	Warrior* war = new Warrior();
	light_warriors.push_front(war);
	light_warriors.push_front(luk);
	light_warriors.push_front(mag);
	Monster_base* def_mnstr = new Monster_base();
	Monster_boss* boss_mnstr = new Monster_boss();
	Monster_base_better* base_better_mnstr = new Monster_base_better();
	dark_warriors.push_front(base_better_mnstr);
	dark_warriors.push_front(boss_mnstr);
	dark_warriors.push_front(def_mnstr);
	cout << "Хп лука:" << luk->hp() << '\n';
	for (int i = 0; i < 3; i++) {
		idx = det_person(dark_warriors.find(i));
		if (idx == 1)
			dynamic_cast<Monster_base*>(dark_warriors.find(i))->choose_attack(light_warriors);
		else if (idx == 2)
			dynamic_cast<Monster_boss*>(dark_warriors.find(i))->choose_attack(light_warriors);
		else if (idx == 3)
			dynamic_cast<Monster_base_better*>(dark_warriors.find(i))->choose_attack(light_warriors);
	}
	cout << "Хп лука:" << luk->hp() << '\n'; 
	delete def_mnstr;
	delete boss_mnstr;
	delete base_better_mnstr;
	delete mag;
	delete luk;
	delete war;
	return 0;
}