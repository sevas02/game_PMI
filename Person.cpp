#include <iostream>
#include "Person.h"
using namespace std;

//функция увелечения маны после удара
void Person::rise_mana(Person* enemy) {
	if (enemy->hp() <= 0) {
		_mana += 0.5 * _dmg;
	}
	else {
		_mana += 0.3 * _dmg;
	}
}

//функция удара
void Person::deal_dmg(Person* enemy, int dmg) {
	if (enemy->_armor)
		enemy->Set_armor(0);
	else
		enemy->Set_hp(enemy->hp() - dmg);
	rise_mana(enemy);
}

//функция нанесения урона ядом
void Person::rec_poison_dmg() {
	if (_time_poison != 0) {
		_hp -= 5;
		_time_poison--;
	}
}

//функция нанесения урона кровотечением
void Person::rec_bleed_dmg() {
	if (_time_bleed != 0) {
		_hp -= 5;
		_time_bleed--;
	}
}

inline ostream& operator<<(ostream& output, const Person& hero) {
	output << hero._name << "\n";
	output << "Количество здоровья: " << hero._hp << "\n";
	return output;
}

void Person::operator =(Person& per) {
	_hp = per._hp;
	_max_hp = per._max_hp; 
	_dmg = per._dmg; 
	_mana = per._mana; 
	_armor = per._armor; 
	_time_bleed = per._time_bleed; 
	_time_poison = per._time_poison; 
	_name = per._name;
}