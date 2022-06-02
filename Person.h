#ifndef PERSON
#define PERSON
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include "List.h"
using namespace std;

class Person {
protected:
	int _hp; //здоровье
	int _max_hp; //максимальное здоровье
	int _dmg; //урон
	double _mana; //мана
	bool _armor; //щит
	int _time_bleed; //время кровточения
	int _time_poison; //время отравления
	string _name;
public:
	//Геттеры
	int hp() { return _hp; }
	int max_hp() { return _max_hp; }
	int dmg() { return _dmg; }
	double mana() { return _mana; }
	bool armor() { return _armor; }
	int time_bleed() { return _time_bleed; }
	int time_poison() { return _time_poison; }
	string name() { return _name; }

	//Сеттеры
	void Set_hp(int hp) { _hp = hp; }
	void Set_dmg(int dmg) { _dmg = dmg; }
	void Set_mana(double mana) { _mana = mana; }
	void Set_armor(bool armor) { _armor = armor; }
	void Set_time_bleed(int time_bleed) { _time_bleed = time_bleed; }
	void Set_time_poison(int time_poison) { _time_poison = time_poison; }

	//Функции для добавления ходов к значениям отравления и кровотечения
	void app_time_bleed(int app_time_bleed) { _time_bleed += app_time_bleed; }
	void app_time_poison(int app_time_poison) { _time_poison += app_time_poison; }

	//пополнение маны
	void rise_mana(Person* enemy);

	//нанесение урона
	void deal_dmg(Person* enemy, int dmg);

	//получение урона (recieve)
	void rec_dmg(Person enemy) { _hp -= ((_armor == true) ? _armor = false : _dmg); }

	//получение хп (recieve)
	void rec_hp(int val) { _hp += val; }

	//обнуление маны
	void null_mana() { _mana = 0; }

	//получение брони
	void recieve_armor() { _armor = true; }

	//получение урона от отравления
	void rec_poison_dmg();

	//получение урона от кровотечения
	void rec_bleed_dmg();

	//функция определения атаки у юнита
	virtual void choose_ability() { ; }

	friend ostream& operator<<(ostream& output, const Person& hero);
};


#endif