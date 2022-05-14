#include <iostream>
#include <deque>
#include "Monsters.h"
using namespace std;

//Конструктор для базового монстра
Monster_base::Monster_base() {
	_hp = 100;
	_dmg = 10;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

//функция атаки монстров
void Monster_base::Monster_attack(Person& enemy) {
	deal_dmg(enemy, _dmg);
	int num = 1 + rand() % 10;
	//если повезет и выпадет или 1 или 2(т.е урон нанесется с 20% шансом)
	if (num == 1 || num == 2) {
		//3 - число ходов
		enemy.app_time_poison(3);
		enemy.rec_poison_dmg();
	}
	_mana = 0;
}

//Деструктор для базового монстра
Monster_base::~Monster_base() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

//Конструктор для монстра босса
Monster_boss::Monster_boss() {
	_hp = 200;
	_dmg = 20;
	_mana = 0;
	_armor = 1;
	_time_bleed = 0;
	_time_poison = 0;
}

//Супер атака босса монстра
void Monster_boss::Monster_boss_sup_attack(deque<Person> enemies) {
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].app_time_poison(5);
		enemies[i].rec_poison_dmg();
	}
	_mana = 0;
}

//Деструктор для монстра босса
Monster_boss::~Monster_boss() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

//конструктор для монстра (чуть лучше базового)
Monster_base_better::Monster_base_better() {
	_hp = 120;
	_dmg = 15;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

//функция суперудара
void Monster_base_better::Monster_sup_attack(Person& enemy) {
	deal_dmg(enemy, _dmg / 2);
	//5 - число ходов
	enemy.app_time_poison(5);
	enemy.rec_poison_dmg();
}

//деструктор для монстра (чуть лучше базового)
Monster_base_better::~Monster_base_better() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

Monster_vampire::Monster_vampire() {
	_hp = 60;
	_dmg = 30;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

void Monster_vampire::vampire_attack(Person& enemy) {
	deal_dmg(enemy, _dmg / 2);
	//5 - число ходов
	enemy.app_time_bleed(5);
	enemy.rec_bleed_dmg();
	//в дальнейшем планируется сделать пополнение здоровья в течение игры а не сразу
	_hp += 25;
	_mana = 0;
}

Monster_vampire::~Monster_vampire() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}