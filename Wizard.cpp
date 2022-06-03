#include "Wizard.h"
#include "List.h"
using namespace std;

Wizard::Wizard() {
	_hp = 120;
	_max_hp = 120;
	_dmg = 30;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Маг";
}

void Wizard::super_healing(Person* kent) {
	int val = kent->max_hp() * val_heal;
	kent->rec_hp(val);
	if (kent->hp() > kent->max_hp())
		kent->Set_hp(kent->max_hp());
	null_mana();
}

void Wizard::super_fire_punch(list<Person*>& enemies) {
	srand(time(0));
	//рандомим событие
	int num = rand() % 10 + 1;
	//рандомим врага
	int idx = rand() % (enemies.size());
	//урон при срабатывании пассивки (40% от базового)
	int temp_dmg = val_fire_dmg * dmg();
	if (num <= 2) 
		deal_dmg(enemies.find_value(idx), temp_dmg);
}

void Wizard::choose_ability(list<Person*>& enemies, list<Person*>& kents) {
	int idx;
	cout << "Выберите действие: 1 - обычная атака, 2 - лечение ";
	cin >> idx;
	if (idx == 1) {
		cout << "Выберите противника\n";
		cin >> idx;
		Person* enemy = enemies.find_value(idx - 1);
		deal_dmg(enemy, dmg());
		super_fire_punch(enemies);
	}
	if (idx == 2) {
		cout << "Выберите союзника\n";
		cin >> idx;
		Person* kent = kents.find_value(idx - 1);
		super_healing(kent);
	}
}

Wizard::~Wizard() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}