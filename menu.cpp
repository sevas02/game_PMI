#include "menu.h"
#include "Checkers.h"
#include "Motion.h"
#include "Stack.h"
#include "draw.h"
#include <iostream>
#define underline "\033[4m"
#define no_underline "\033[0m"
using namespace std;

void print(list<Person*>& list) {
	for (int i = 0; i < list.size(); i++) {
	Person* obj = list.find_value(i);
		cout << "\n" << i + 1 << "."  << *obj << " \n";
	}
}

void choose_light_person(list<Person*>& light_warriors, int num) {
	int hero_num, index = 0;
	Wizard* mag;
	Warrior* war;
	Archer* arch;
	cout << underline << "\nВыберите светлого персонажа:" << no_underline << '\n';
	cout << "1.Маг\n2.Воин\n3.Лучник" << '\n';
	while (index !=num) {
		hero_num = check_idx(3);
		switch (hero_num) {

		case 1:
		mag = new Wizard();
		light_warriors.push_front(mag); 
		index++; 
		break;

		case 2:
		war = new Warrior();
		light_warriors.push_front(war);
		index++;
		break;

		case 3:
		arch = new Archer();
		light_warriors.push_front(arch);
		index++;
		break;
		}

	}
	cout << underline << "\nВаш выбор:" << no_underline << "\n";
	print(light_warriors);
}

void choose_dark_person(list<Person*>& dark_warriors, int num) {
	int monster_num, index = 0;
	Monster_base* m_b;
	Monster_better* m_b_b;
	Monster_boss* m_boss;
	cout << underline << "\nВыберите темного персонажа:" << no_underline << "\n";
	cout << "1.Обычный монстр\n2.Улучшенный монстр\n3.Босс" << '\n';
	while (index != num) {
		monster_num = check_idx(3);
		switch (monster_num) {

		case 1:
		m_b = new Monster_base();
		dark_warriors.push_front(m_b);
		index++;
		break;

		case 2:
		m_b_b = new Monster_better();
		dark_warriors.push_front(m_b_b);
		index++;
		break;

		case 3:
		m_boss = new Monster_boss();
		dark_warriors.push_front(m_boss);
		index++; 
		break;
		}
	}
	cout << underline << "\nВаш выбор:" << no_underline << "\n";
	print(dark_warriors);
}

int get_idx_dark(Person* hero) {
	if (typeid(*hero) == typeid(Monster_base))
		return 1;
	else if (typeid(*hero) == typeid(Monster_boss))
		return 2;
	else if (typeid(*hero) == typeid(Monster_better))
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
	int idx = 0, ans = 0;
	motion step;
	for (int i = 0; i < dark_warriors.size(); i++) {
		if (light_warriors.size() == 0)
			break;
		step.copy_list2list(light_warriors, dark_warriors);
		print(light_warriors);
		idx = get_idx_dark(dark_warriors.find_value(i));
		if (idx == 1)
			dynamic_cast<Monster_base*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		else if (idx == 2)
			dynamic_cast<Monster_boss*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		else if (idx == 3)
			dynamic_cast<Monster_better*>(dark_warriors.find_value(i))->choose_ability(light_warriors);
		check_person_hp(light_warriors);
		glClear(GL_COLOR_BUFFER_BIT);
		draw_side(light_warriors, 1, light_warriors.size());
		draw_side(dark_warriors, 5, dark_warriors.size());
		cout << "Хотите вернуть обратно?" << "\n";
		cin >> ans;
		if (ans == 1) {
			step.return_list2list(dark_warriors, light_warriors);
			i--;
		}
	}
	check_person_time_poison(dark_warriors);
	check_person_time_bleed(dark_warriors);
}

void light_persons_step(list<Person*>& dark_warriors, list<Person*>& light_warriors) {
	int idx = 0, ans = 0;
	motion step;
	for (int i = 0; i < light_warriors.size(); i++) {
		if (dark_warriors.size() == 0)
			break;
		step.copy_list2list(light_warriors, dark_warriors);
		print(dark_warriors);
		idx = get_idx_light(light_warriors.find_value(i));
		if (idx == 1)
			dynamic_cast<Wizard*>(light_warriors.find_value(i))->choose_ability(dark_warriors, light_warriors);
		else if (idx == 2)
			dynamic_cast<Warrior*>(light_warriors.find_value(i))->choose_ability(dark_warriors, light_warriors);
		else if (idx == 3)
			dynamic_cast<Archer*>(light_warriors.find_value(i))->choose_ability(dark_warriors);
		check_person_hp(dark_warriors);
		glClear(GL_COLOR_BUFFER_BIT);
		draw_side(light_warriors, 1, light_warriors.size());
		draw_side(dark_warriors, 5, dark_warriors.size());
		cout << "Хотите вернуть обратно?" << "\n";
		cin >> ans;
		if (ans == 1) {
			step.return_list2list(dark_warriors, light_warriors);
			i--;
		}
	}
	check_person_time_poison(light_warriors);
	check_person_time_bleed(light_warriors);
}

void check_person_hp(list<Person*>& heroes) {
	for (int i = 0; i < heroes.size(); i++) {
		if (heroes.find_value(i)->hp() <= 0) {
			//светлокрасный цвет
			SetColor(12, 0);
			cout << heroes.find_value(i)->name() << " мёртв" << "\n";
			SetColor(7, 0);
			heroes.delete_element(i);
		}
	}
}

//проверка персонажей на кровотечение
void check_person_time_bleed(list<Person*>& heroes) {
	for (int i = 0; i < heroes.size(); i++)
		if (heroes.find_value(i)->time_bleed() > 0) {
			heroes.find_value(i)->rec_bleed_dmg();
			//светлокрасный цвет
			SetColor(4, 0);
			cout << heroes.find_value(i)->name() << " теряет 5 hp от кровотечения" << "\n";
			SetColor(7, 0);
		}
}

//проверка персонажей на отравление
void check_person_time_poison(list<Person*>& heroes) {
	for (int i = 0; i < heroes.size(); i++)
		if (heroes.find_value(i)->time_poison() > 0) {
			heroes.find_value(i)->rec_bleed_dmg();
			//светлозеленый цвет
			SetColor(10, 0);
			cout << heroes.find_value(i)->name() << " теряет 5 hp от отравления" << "\n";
			SetColor(7, 0);
		}
}

