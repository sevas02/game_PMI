#include "Monsters.h"
#include "menu.h"
#include "Checkers.h"
#include <iostream>
#include <Windows.h>
#define underline "\033[4m"
#define no_underline "\033[0m"
using namespace std;

//Конструктор для базового монстра
Monster_base::Monster_base() {
	_hp = 100;
	_max_hp = 100;
	_dmg = 10;
	_mana = 100;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Zombie";
}

//функция атаки монстров
void Monster_base::Monster_attack(Person& enemy) {
	srand(time(0));
	deal_dmg(&enemy, dmg());
	//прибавление 1 необходимо для нормального подсчета процентов
	int num = 1 + rand() % 10;
	//урон нанесется с 20% шансом
	if (num <= 2) {
		//3 - число ходов
		enemy.app_time_poison(3);
		enemy.rec_poison_dmg();
	}
}

//функция выбора атаки для обычного монстра
void Monster_base::choose_ability(list<Person*>& enemies) {
	int index;
	cout << underline << "\nВы ходите за обычного монстра\n" << no_underline;
	cout << "Выберите действие:\n1.обычная атака\n";
	index = check_idx(1);
	if (index == 1) {
		cout << underline << "\nВыберите противника " << no_underline << "\n";
		print(enemies);
		index = check_idx(enemies.size());
		Person* man = enemies.find_value(index - 1);
		Monster_attack(*man);
	}
}

//Деструктор для базового монстра
Monster_base::~Monster_base() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}


//Конструктор для монстра босса
Monster_boss::Monster_boss() {
	_hp = 200;
	_max_hp = 200;
	_dmg = 20;
	_mana = 0;
	_armor = 1;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "BOSS";
}

//Супер атака босса монстра
void Monster_boss::Monster_boss_sup_attack(list<Person*>& enemies) {
	for (int i = 0; i < enemies.size(); i++) {
		enemies.find_value(i)->app_time_poison(5);
		enemies.find_value(i)->rec_poison_dmg();
	}
	null_mana();
}

void Monster_boss::choose_ability(list<Person*>& enemies) {
	int index;
	bool flag = 0;
	Person* man = 0;
	cout << underline << "Вы ходите за монстра босса" << "| " << mana() <<
	" ед. маны |\n" << no_underline;
	cout << "Выберите действие:\n1.обычная атака\n2.супер-атака\n";
	while (flag != 1) {
		index = check_idx(2);
		switch (index) {
		case 1:
			cout << underline << "\nВыберите противника " << no_underline << "\n";
			print(enemies);
			index = check_idx(enemies.size());
			man = enemies.find_value(index - 1);
			Monster_attack(*man);
			flag = 1;
			break;
		case 2:
			if (mana() <= 10) {
				cout << "Недостаточно маны! Повторите ввод!\n";
				break;
			}
			Monster_boss_sup_attack(enemies);
			flag = 1;
			break;
		}
	}
}

//Деструктор для монстра босса
Monster_boss::~Monster_boss() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}

//конструктор для монстра (чуть лучше базового)
Monster_better::Monster_better() {
	_hp = 120;
	_max_hp = 120;
	_dmg = 15;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Toplyak";
}

//функция суперудара
void Monster_better::Monster_sup_attack(Person& enemy) {
	//нанесенный урон уменьшается в два раза
	deal_dmg(&enemy, dmg() / 2);
	//5 - число ходов
	enemy.app_time_poison(5);
	enemy.rec_poison_dmg();
}

//функция выбора способности для базового монстра
void Monster_better::choose_ability(list<Person*>& enemies) {
	int index;
	bool flag = 0;
	Person* man = 0;
	cout << underline << "Вы ходите за улучшенного монстра" << "| " << mana() << 
		" ед. маны |\n" << no_underline; no_underline;
	cout << "\nВыберите действие:\n1.обычная атака\n2.супер-атака " <<"\n";
	while (flag != 1) {
		index = check_idx(2);
		switch (index) {
		case 1:
			cout << underline << "\nВыберите противника " << no_underline << "\n";
			print(enemies);
			index = check_idx(enemies.size());
			man = enemies.find_value(index - 1);
			Monster_attack(*man);
			flag = 1;
			break;
		case 2:
			if (mana() <= 10) {
				cout << "Недостаточно маны! Повторите ввод!\n";
				break;
			}
			cout << underline << "\nВыберите противника " << no_underline << "\n";
			print(enemies);
			index = check_idx(enemies.size());
			man = enemies.find_value(index - 1);
			Monster_sup_attack(*man);
			flag = 1;
			break;
		}
	}
}

//деструктор для монстра (чуть лучше базового)
Monster_better::~Monster_better() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}
