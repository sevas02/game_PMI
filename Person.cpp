#include <iostream>
#include "Person.h"
using namespace std;

//Функция кровотечения
void Person::app_time_bleed(int app_time_bleed) {
	SetColor(4, 0);
	cout << _name << " получил кровотечение на " << app_time_bleed << " хода" << "\n";
	SetColor(7, 0);
	_time_bleed += app_time_bleed; 
}
 //Функция отравления
void Person::app_time_poison(int app_time_poison) {
	SetColor(10, 0);
	cout << _name << " получил отравление на " << app_time_poison << " хода" << "\n";
	SetColor(7, 0);
	_time_poison += app_time_poison; 
}

//Функция увелечения маны после удара
void Person::rise_mana(Person* enemy) {
	if (enemy->hp() <= 0) 
		_mana += 0.5 * _dmg;
	else 
		_mana += 0.3 * _dmg;
}

//Функция удара
void Person::deal_dmg(Person* enemy, int dmg) {
	if (enemy->_armor)
		enemy->Set_armor(0);
	else
		enemy->Set_hp(enemy->hp() - dmg);
	rise_mana(enemy);
}

//Функция нанесения урона ядом
void Person::rec_poison_dmg() {
	if (_time_poison != 0) {
		_hp -= 10;
		_time_poison--;
	}
}

//Функция нанесения урона кровотечением
void Person::rec_bleed_dmg() {
	if (_time_bleed != 0) {
		_hp -= 5;
		_time_bleed--;
	}
}

//Конструктор копирования
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