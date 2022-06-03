#include "menu.h"
#include <iostream>
using namespace std;

void print(list<Person*>& list) {
	for (int i = 0; i < list.size(); i++) {
	Person* obj = list.find_value(i);
		cout << *obj << " \n";
	}
}

void choose_light_person(list<Person*>& light_warriors, int num) {
	int hero_num, idx = 0;
	Wizard* mag;
	Warrior* war;
	Archer* arch;
	cout << "Выберите светлого персонажа:" << '\n';
	cout << "1 - Маг, 2 - Воин, 3 - Лучник" << '\n';
	while (idx !=num) {
		cin >> hero_num;
		switch (hero_num) {

		case 1:
		mag = new Wizard();
		light_warriors.push_front(mag); 
		idx++; 
		break;

		case 2:
		war = new Warrior();
		light_warriors.push_front(war);
		idx++;
		break;

		case 3:
		arch = new Archer();
		light_warriors.push_front(arch);
		idx++;
		break;
		}

	}
	cout << "Ваш выбор:" << "\n";
	print(light_warriors);
}

void choose_dark_person(list<Person*>& dark_warriors, int num) {
	int monster_num, idx = 0;
	Monster_base* m_b;
	Monster_base_better* m_b_b;
	Monster_boss* m_boss;
	cout << "Выберите темного персонажа:" << "\n";
	cout << "1 - Обычный монстр, 2 - Улучшенный монстр, 3 - Босс" << '\n';
	while (idx != num) {
		cin >> monster_num;
		switch (monster_num) {

		case 1:
		m_b = new Monster_base();
		dark_warriors.push_front(m_b);
		idx++;
		break;

		case 2:
		m_b_b = new Monster_base_better();
		dark_warriors.push_front(m_b_b);
		idx++;
		break;

		case 3:
		m_boss = new Monster_boss();
		dark_warriors.push_front(m_boss);
		idx++; 
		break;
		}
	}
	cout << "Ваш выбор:" << "\n";
	print(dark_warriors);
}

int get_idx_dark(Person* hero) {
	if (typeid(*hero) == typeid(Monster_base))
		return 1;
	else if (typeid(*hero) == typeid(Monster_boss))
		return 2;
	else if (typeid(*hero) == typeid(Monster_base_better))
		return 3;
	else
		return -1;
}

int get_idx_light(Person* hero) {
	if (typeid(*hero) == typeid(Wizard))
		return 1;
	else if (typeid(*hero) == typeid(Warrior))
		return 2;
	else if (typeid(*hero) == typeid(Archer))
		return 3;
	else
		return -1;
}

void dark_persons_step(list<Person*>& dark_warriors, list<Person*>& light_warriors) {
	int idx = 0;
	for (int i = 0; i < dark_warriors.size(); i++) {
		print(light_warriors);
		idx = get_idx_dark(dark_warriors.find_value(i));
		if (idx == 1)
			dynamic_cast<Monster_base*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		else if (idx == 2)
			dynamic_cast<Monster_boss*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		else if (idx == 3)
			dynamic_cast<Monster_base_better*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		check_person_hp(light_warriors);
	}
}

void light_persons_step(list<Person*>& dark_warriors, list<Person*>& light_warriors) {
	int idx = 0;
	for (int i = 0; i < light_warriors.size(); i++) {
		print(dark_warriors);
		idx = get_idx_light(light_warriors.find_value(i));
		if (idx == 1)
			dynamic_cast<Wizard*>(light_warriors.find_value(i))->choose_ability(dark_warriors, light_warriors);
		else if (idx == 2)
			dynamic_cast<Warrior*>(light_warriors.find_value(i))->choose_ability(dark_warriors, light_warriors);
		else if (idx == 3)
			dynamic_cast<Archer*>(light_warriors.find_value(i))->choose_ability(dark_warriors);
		check_person_hp(dark_warriors);
	}
}

void check_person_hp(list<Person*>& heroes) {
	for (int i = 0; i < heroes.size(); i++) {
		if (heroes.find_value(i)->hp() <= 0) {
			cout << heroes.find_value(i)->name() << " умер" << "\n";
			heroes.delete_element(i);
		}
	}
}





