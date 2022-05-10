#include <iostream>
#include <vector>
#include "Wizard.h"
#include "Person.h"
using namespace std;

Wizard::Wizard() {
	_hp = 120;
	_dmg = 30;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

void Wizard::super_healing(Person &kent) {
	//���� ����� ��������, � �� ��� ������� ��������� kent.hp
	int val = kent.hp * val_heal;
	kent.rec_hp(val);
	null_mana();
}

void Wizard::super_fire_punch(vector<Person>& enemies) {
	//�������� �������
	int num = rand() % 10 + 1;
	//�������� �����
	int idx = rand() % (enemies.size() - 1);
	//���� ��� ������������ �������� (50% �� ��������)
	int temp_dmg = 0.5*_dmg;
	if (num <= 2) 
		deal_dmg(enemies[idx], temp_dmg);
}

Wizard::~Wizard() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}