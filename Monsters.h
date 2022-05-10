#ifndef MONSTER
#define MONSTER
#include "Person.h"
#include <iostream>
#include <deque>

//базовый монстр
//одна атака - нанесение урона с возможным отравлением(есть у всех монстров)
class Monster_base : public Person {
public:
	//Конструктор
	Monster_base();
	
	//функция атаки монстра
	void Monster_attack(Person& enemy);

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

	//функция супер атаки монстра босса
	void Monster_boss_sup_attack(deque<Person> enemies);

	//Деструктор
	~Monster_boss();
};

//Улучшенный монстр
//Увеличенное здоровье
//Супер удар - гаранитрованное отравление героя и нанесение ему урона 
class Monster_base_better : public Monster_base {
public:
	Monster_base_better();

	//функция супер атаки для монстра
	void Monster_sup_attack(Person& enemy);

	~Monster_base_better();
};

//Вампир
//Мало здоровья, много урона
//Супер удар - высасывание крови у оппонента
class Monster_vampire : public Monster_base {
public:
	Monster_vampire();

	void vampire_attack(Person& enemy);

	~Monster_vampire();
};

#endif