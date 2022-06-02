#include "Warrior.h"
#include "List.h"
using namespace std;

//Конструктор 
Warrior::Warrior() {
	_hp = 100;
	_max_hp = 100;
	_dmg = 10;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	//_name = "Воин";
}

//Деструктор 
Warrior::~Warrior() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	//_name = "";
}

// дать бронь союзникам
void Warrior::give_shield(Person& ally) {
	ally.Set_armor(true);
}

// Cупер сила
void Warrior::Warrior_super_attack() {
	if (_mana < 50)
		cout << "недостаточно маны! " << endl;
	else {
		_hp += 30;
		_dmg += 5;
		null_mana();
	}
}

//Функция атаки 
void Warrior::Warrior_attack(Person& enemy) {
	srand(time(0));
	deal_dmg(&enemy, _dmg);
	int temp = 1 + rand() % 10;
	// шанс нанести урон с кровотечением - 30%
	if (temp <= 3) {
		enemy.app_time_poison(2);
		enemy.rec_bleed_dmg();
		_mana += 5;
	}
	_mana += 10;
}

void Warrior::choose_ability(list<Person*>& enemies, list<Person*>& kents) {
	int idx;
	cout << "Выберите действие: 1 - обычная атака, 2 - баффалка, 3 - снарядить щитом ";
	cin >> idx;
	if (idx == 1) {
		cout << "Выберите врага\n";
		cin >> idx;
		Person* man = enemies.find(idx - 1);
		Warrior_attack(*man);
	}
	if (idx == 2) {
		Warrior_super_attack();
	}
	if (idx == 3) {
		cout << "Выберите союзника\n";
		cin >> idx;
		Person* man = kents.find(idx - 1);
		give_shield(*man);
	}
}