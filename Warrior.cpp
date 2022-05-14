#include <iostream>
#include "Warrior.h"
using namespace std;

//Конструктор 
Warrior::Warrior() {
	_hp = 100;
	_dmg = 10;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

//Деструктор 
Warrior::~Warrior() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

// дать бронь союзникам
void Warrior::give_shield(Person& ally) {
	ally.Set_armor(true);
}

// Cупер сила
void Warrior::Warrior_super_attack() {
	if (_mana < 50)
		cout << "недостаточно маны" << endl;
	else {
		_hp += 30;
		_dmg += 5;
		_mana -= 50;
	}
}

//Функция атаки 
void Warrior::Warrior_attack(Person& enemy) {
	deal_dmg(enemy, _dmg);
	int temp = 1 + rand() % 10;
	// шанс нанести урон с кровотечением - 30%
	if (temp == 1 || temp == 2 || temp == 2) {
		enemy.app_time_poison(2);
		enemy.rec_bleed_dmg();
		_mana += 5;
	}
	_mana += 10;
}

//функция блокировки монстра на 1 ход (т.е воин бросает сеть на монстра и он не активен на протяжении одного хода 
/* функйии спецприемов, которые можно примерить при возникновении специфических ситуаций в бою
   например, спецудар, который можно сделать только после того как вы заблокируете атаку монстра цитом*/