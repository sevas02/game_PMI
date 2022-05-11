#include <iostream>
#include <vector>
#include "Wizard.h"
#include "Person.h"
#include <ctime>
using namespace std;

Wizard::Wizard() {
	_hp = 120;
	_dmg = 30;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

void Wizard::super_healing(Person& kent) {
	//надо брать максимум, а не текущее значение kent.hp
	int val = kent.hp() * val_heal;
	kent.rec_hp(val);
	null_mana();
}

void Wizard::super_fire_punch(vector<Person>& enemies) {
	srand(time(0));
	//рандомим событие
	int num = rand() % 10 + 1;
	//рандомим врага
	int idx = rand() % (enemies.size() - 1);
	//урон при срабатывании пассивки (50% от базового)
	int temp_dmg = 0.5*_dmg;
	if (num <= 2) {
		deal_dmg(enemies[idx], temp_dmg);
		cout << "Нанесен урон противнику с номером " << idx << "у него осталось " << enemies[idx].hp() << "хп" << endl;
	}
	else
		cout << "Выпал номер " << num << endl;

}

Wizard::~Wizard() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}