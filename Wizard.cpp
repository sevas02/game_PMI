#include "Wizard.h"
#include "List.h"
#include "menu.h"
#define underline "\033[4m"
#define no_underline "\033[0m"
using namespace std;

Wizard::Wizard() {
	_hp = 60;
	_max_hp = 60;
	_dmg = 25;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Wizard";
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
	cout << underline << "\nВы ходите за мага " <<
		"| " << mana() << " ед. маны |\n" << no_underline;
	cout << "Выберите действие:\n1.обычная атака\n2.лечение\n";
	idx = check_idx(2);
	if (idx == 1) {
		cout << underline << "\nВыберите противника\n" << no_underline;
		print(enemies);
		idx = check_idx(enemies.size());;
		Person* enemy = enemies.find_value(idx - 1);
		deal_dmg(enemy, dmg());
		super_fire_punch(enemies);
	}
	else if (idx == 2) {
		if (mana() <= 10) {
			cout << "Недостаточно маны! Повторите ввод!\n";
			choose_ability(enemies, kents);
			return;
		}
		cout << underline << "\nВыберите союзника\n" << no_underline;
		print(kents);
		idx = check_idx(kents.size());
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