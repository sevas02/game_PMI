#ifndef WARRIOR
#define WARRIOR
#include "Person.h"
#include <iostream>
#include <stack>

class Warrior : public Person {
public:
	//Конструктор
	Warrior();

	//Деструктор
	~Warrior();

	// дать бронь союзникам
	void give_shield(Person& ally);

	// Cупер сила
	void Warrior_super_attack();

	//Функция атаки 
	void Warrior_attack(Person& enemy);
};


#endif//WARRIOR
