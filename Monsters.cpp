#include "Monsters.h"
#include <iostream>
#include <Windows.h>
using namespace std;

//Конструктор для базового монстра
Monster_base::Monster_base() {
	_hp = 100;
	_max_hp = 100;
	_dmg = 10;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Обычный монстр";
}

//функция атаки монстров
void Monster_base::Monster_attack(Person& enemy) {
	srand(time(0));
	deal_dmg(&enemy, dmg());
	int num = 1 + rand() % 10;
	//урон нанесется с 20% шансом
	if (num <= 2) {
		//3 - число ходов
		enemy.app_time_poison(3);
		enemy.rec_poison_dmg();
	}
	null_mana();
}

void Monster_base::choose_ability(list<Person*>& enemies) {
	int idx;
	cout << "Вы ходите за обычного монстра" << "\n";
	cout << "Выберите действие: 1 - обычная атака ";
	cin >> idx;
	if (idx == 1) {
		cout << "Выберите противника " << "\n";
		cin >> idx;
		Person* man = enemies.find_value(idx - 1);
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
	_name = "БОРОВ";
}

//Супер атака босса монстра
void Monster_boss::Monster_boss_sup_attack(list<Person*>& enemies) {
	for (int i = 0; i < enemies.size(); i++) {
		enemies.find_value(i)->app_time_poison(5);
		enemies.find_value(i)->rec_poison_dmg();
	}
	null_mana();
}

void Monster_boss::choose_ability(list<Person*>& enimies) {
	int idx;
	cout << "Вы ходите за монстра босса" << "\n";
	cout << "Выберите действие: 1 - обычная атака, 2 - супер-атака ";
	cin >> idx;
	if (idx == 1) {
		cout << "Выберите противника " << "\n";
		cin >> idx;
		Person* man = enimies.find_value(idx - 1);
		Monster_attack(*man);
	}
	else
		Monster_boss_sup_attack(enimies);

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
Monster_base_better::Monster_base_better() {
	_hp = 120;
	_max_hp = 120;
	_dmg = 15;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Свин";
}

//функция суперудара
void Monster_base_better::Monster_sup_attack(Person& enemy) {
	deal_dmg(&enemy, dmg() / 2);
	//5 - число ходов
	enemy.app_time_poison(5);
	enemy.rec_poison_dmg();
}

void Monster_base_better::choose_ability(list<Person*>& enemies) {
	int idx;
	cout << "Вы ходите за улучшенного монстра" << "\n";
	cout << "Выберите действие: 1 - обычная атака, 2 - супер-пупер ";
	cin >> idx;
	if (idx == 1) {
		cout << "Выберите противника " << "\n";
		cin >> idx;
		Person* man = enemies.find_value(idx - 1);
		Monster_attack(*man);
	}
	else {
		cout << "Выберите противника " << "\n";
		cin >> idx;
		Person* man = enemies.find_value(idx - 1);
		Monster_sup_attack(*man);
	}
}

//деструктор для монстра (чуть лучше базового)
Monster_base_better::~Monster_base_better() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}

Monster_vampire::Monster_vampire() {
	_hp = 60;
	_max_hp = 60;
	_dmg = 30;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Вампир";
}

void Monster_vampire::vampire_attack(Person& enemy) {
	deal_dmg(&enemy, dmg() / 2);
	//5 - число ходов
	enemy.app_time_bleed(5);
	enemy.rec_bleed_dmg();
	//в дальнейшем планируется сделать пополнение здоровья в течение игры а не сразу
	_hp += 25;
	null_mana();
}

Monster_vampire::~Monster_vampire() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}