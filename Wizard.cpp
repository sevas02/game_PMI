#include "Wizard.h"

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

void Wizard::super_fire_punch(vector<Person*>& enemies) {
	srand(time(0));
	//рандомим событие
	int num = rand() % 10 + 1;
	//рандомим врага
	int idx = rand() % (enemies.size() - 1);
	//урон при срабатывании пассивки (40% от базового)
	int temp_dmg = val_fire_dmg * _dmg;
	if (num <= 2) {
		deal_dmg(enemies[idx], temp_dmg);
		cout << "Нанесен урон противнику с номером " << idx << "у него осталось " << enemies[idx]->hp() << "хп" << endl;
	}
	else
		cout << "Выпал номер " << num << endl;
	null_mana();
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