#ifndef MONSTER
#define MONSTER
#include "Person.h"
#include <iostream>

//базовый монстр
//одна атака - нанесение урона с возможным отравлением(есть у всех монстров)
class Monster_base : public Person {
public:
	//Конструктор
	Monster_base();

	//Конструктор копирования
	Monster_base(Person& war);

	//Функция атаки монстра
	void Monster_attack(Person& enemy);

	//Функция выбора атаки
	virtual void choose_ability(list<Person*>& enemies);

	//Деструктор
	~Monster_base();
};

//монстр босс
//Различия с обычным - больше здорвоья, есть защита, наносит больше урона
//Супер удар - отравление всех персонажей оппонента

class Monster_boss : public Monster_base {
public:
	//Конструктор
	Monster_boss();

	//Конструктор копирования
	Monster_boss(Person& war);

	//Функция супер атаки монстра босса
	void Monster_boss_sup_attack(list<Person*>& enemies);

	//Функция выбора атаки
	void choose_ability(list<Person*>& enemy);

	//Деструктор
	~Monster_boss();
};

//Улучшенный монстр
//Увеличенное здоровье
//Супер удар - гаранитрованное отравление героя и нанесение ему урона 
class Monster_better : public Monster_base {
public:
	//Конструктор
	Monster_better();

	//Конструктор копирования
	Monster_better(Person& war);

	//Функция супер атаки для монстра
	void Monster_sup_attack(Person& enemy);

	//Функция выбора атаки
	void choose_ability(list<Person*>& enemies);

	//Деструктор
	~Monster_better();
};

#endif