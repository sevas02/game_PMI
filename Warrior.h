#ifndef WARRIOR
#define WARRIOR
#include "Person.h"
#include <iostream>

class Warrior : public Person {
public:
	//Конструктор
	Warrior();

	//Конструктор копирования
	Warrior(const Warrior& object);

	//Деструктор
	~Warrior();

	//выдать броню союзникам
	void give_shield(Person* kent);

	//увеличение характеристик война
	void Warrior_super_attack();

	//Функция атаки 
	void Warrior_attack(Person* enemy);

	//Функция выбора атаки
	void choose_ability(list<Person*>& enemies, list<Person*>& kents);
};

#endif//WARRIOR