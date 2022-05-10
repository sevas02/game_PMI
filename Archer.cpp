#include <iostream>
#include "Archer.h"
#include "Person.h"
using namespace std;

//конструктор
Archer::Archer() {
	_hp = 80;
	_dmg = 15;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

//супервыстрел 
void Archer::super_arrow_shot(Person& enemy) {
	int temp_dmg = _dmg * 1.75;
	deal_dmg(enemy, temp_dmg);
	null_mana();
}

//град стрел (удар по всем противникам)
void Archer::hail_of_arrows(vector<Person>& enemies) {
	int temp_dmg = _dmg * 0.75;
	for (int i = 0; i < enemies.size(); i++)
		deal_dmg(enemies[i], temp_dmg);
	null_mana();
}

Archer::~Archer() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}
