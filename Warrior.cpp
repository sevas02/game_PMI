#include "Warrior.h"
#include "menu.h"
#include "List.h"
#define underline "\033[4m"
#define no_underline "\033[0m"
using namespace std;

//Конструктор
Warrior::Warrior() {
	_hp = 100;
	_max_hp = 100;
	_dmg = 15;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Warrior";
}

//Конструктор копирования
Warrior::Warrior(Person& war) {
	_hp = war.hp();
	_max_hp = war.max_hp();
	_dmg = war.dmg();
	_mana = war.mana();
	_armor = war.armor();
	_time_bleed = war.time_bleed();
	_time_poison = war.time_poison();
	_name = war.name();
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
	_name = "";
}

//Дать броню союзнику
void Warrior::give_shield(Person* kent) {
	kent->Set_armor(true);
	null_mana();
}

//Супер атака война
void Warrior::Warrior_super_attack() {
		_hp += 30;
		_dmg += 5;
		null_mana();
}

//Обычная атака война
void Warrior::Warrior_attack(Person* enemy) {
	srand(time(0));
	deal_dmg(enemy, _dmg);
	//Рандомим число
	int temp = 1 + rand() % 10;
	//Шанс нанести урон с кровотечением - 30%
	if (temp <= 3) {
		enemy->app_time_bleed(2);
		enemy->rec_bleed_dmg();
		_mana += 5;
	}
}

//Функция выбора атаки
void Warrior::choose_ability(list<Person*>& enemies, list<Person*>& kents) {
	int idx;
	cout << underline << "\nВы ходите за воина " <<
		"| " << mana() << " ед. маны |\n" << no_underline;
	cout << "Выберите действие:\n1.обычная атака\n2.улучшение воина\n3.снарядить щитом воина" << "\n";
	idx = check_idx(3);
	if (idx == 1) {
		cout << underline << "\nВыберите противника " << no_underline << "\n";
		print(enemies);
		idx = check_idx(enemies.size());
		Person* man = enemies.find_value(idx - 1);
		Warrior_attack(man);
	}
	else if (idx == 2) {
		if (mana() <= 5) {
			cout << "Недостаточно маны! Повторите ввод!\n";
			choose_ability(enemies, kents);
			return;
		}
		Warrior_super_attack();
	}
	else if (idx == 3) {
		if (mana() <= 10) {
			cout << "Недостаточно маны! Повторите ввод!\n";
			choose_ability(enemies, kents);
			return;
		}
		cout << underline << "\nВыберите союзника " << no_underline << "\n";
		print(kents);
		idx = check_idx(enemies.size());
		Person* man = kents.find_value(idx - 1);
		give_shield(man);
	}
}