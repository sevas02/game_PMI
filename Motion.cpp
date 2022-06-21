#include <iostream>
#include "Motion.h"
#include "menu.h"
using namespace std;

//ФУНКЦИИ КОПИРВАНИЯ ПЕРСОНАЖЕЙ (ДЛЯ ДАЛЬНЕЙШЕГО ОТКАТА)

void motion::copy_light_list2list(list<Person*>& light_wars) {
	Wizard* mag = 0;
	Warrior* war = 0;
	Archer* arch = 0;
	for (int i = 0; i < light_wars.size(); i++) {
		if (typeid(*(light_wars.find_value(i))) == typeid(Wizard)) {
			mag = new Wizard(*(light_wars.find_value(i)));
			_light_wars.push_back(mag);
		}
		else if (typeid(*(light_wars.find_value(i))) == typeid(Warrior)) {
			war = new Warrior(*(light_wars.find_value(i)));
			_light_wars.push_back(war);
		}
		else if (typeid(*(light_wars.find_value(i))) == typeid(Archer)) {
			arch = new Archer(*(light_wars.find_value(i)));
			_light_wars.push_back(arch);
		}
	}
}

void motion::copy_dark_list2list(list<Person*>& dark_wars) {
	Monster_base* mag = 0;
	Monster_boss* war = 0;
	Monster_better* arch = 0;
	for (int i = 0; i < dark_wars.size(); i++) {
		if (typeid(*(dark_wars.find_value(i))) == typeid(Monster_base)) {
			mag = new Monster_base(*(dark_wars.find_value(i)));
			_dark_wars.push_back(mag);
		}
		else if (typeid(*(dark_wars.find_value(i))) == typeid(Monster_boss)) {
			war = new Monster_boss(*(dark_wars.find_value(i)));
			_dark_wars.push_back(war);
		}
		else if (typeid(*(dark_wars.find_value(i))) == typeid(Monster_better)) {
			arch = new Monster_better(*(dark_wars.find_value(i)));
			_dark_wars.push_back(arch);
		}
	}
}

void motion::copy_list2list(list<Person*>& light_wars, list<Person*>& dark_wars) {
	int limit_d = dark_wars.size();
	int limit_l = light_wars.size();
	if (_light_wars.size() != 0)
		for (int i = 0; i < limit_l; i++)
			_light_wars.delete_front();
	if (_dark_wars.size() != 0)
		for (int i = 0; i < limit_d; i++)
			_dark_wars.delete_front();
	copy_dark_list2list(dark_wars);
	copy_light_list2list(light_wars);
}

//ФУНКЦИИ ВОЗВРАТА СОХРАНЕННЫХ ЗАЧЕНИЙ ПЕРСОНАЖЕЙ (ДЛЯ ОТКАТА)

void motion::return_light_list2list(list<Person*>& light_wars) {
	int limit = light_wars.size();
	for (int i = 0; i < limit; i++)
		light_wars.delete_front();
	Wizard* mag = 0;
	Warrior* war = 0;
	Archer* arch = 0;
	for (int i = 0; i < _light_wars.size(); i++) {
		if (typeid(*(_light_wars.find_value(i))) == typeid(Wizard)) {
			mag = new Wizard(*(_light_wars.find_value(i)));
			light_wars.push_back(mag);
		}
		else if (typeid(*(_light_wars.find_value(i))) == typeid(Warrior)) {
			war = new Warrior(*(_light_wars.find_value(i)));
			light_wars.push_back(war);
		}
		else if (typeid(*(_light_wars.find_value(i))) == typeid(Archer)) {
			arch = new Archer(*(_light_wars.find_value(i)));
			light_wars.push_back(arch);
		}
	}
}

void motion::return_dark_list2list(list<Person*>& dark_wars) {
	int limit = dark_wars.size();
	for (int i = 0; i < limit; i++)
		dark_wars.delete_front();
	Monster_base* mag = 0;
	Monster_boss* war = 0;
	Monster_better* arch = 0;
	for (int i = 0; i < _dark_wars.size(); i++) {
		if (typeid(*(_dark_wars.find_value(i))) == typeid(Monster_base)) {
			mag = new Monster_base(*(_dark_wars.find_value(i)));
			dark_wars.push_back(mag);
		}
		else if (typeid(*(_dark_wars.find_value(i))) == typeid(Monster_boss)) {
			war = new Monster_boss(*(_dark_wars.find_value(i)));
			dark_wars.push_back(war);
		}
		else if (typeid(*(_dark_wars.find_value(i))) == typeid(Monster_better)) {
			arch = new Monster_better(*(_dark_wars.find_value(i)));
			dark_wars.push_back(arch);
		}
	}
}

void motion::return_list2list(list<Person*>& dark_wars, list<Person*>& light_wars) {
	return_light_list2list(light_wars);
	return_dark_list2list(dark_wars);
}