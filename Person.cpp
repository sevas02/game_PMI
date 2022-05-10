#include <iostream>
#include "Person.h"
using namespace std;

//������� ���������� ���� ����� �����
void Person::rise_mana(Person enemy) {
	if (enemy._hp <= 0) {
		_mana += 0.5 * _dmg;
	}
	else {
		_mana += 0.3 * _dmg;
	}
}

//������� �����
void Person::deal_dmg(Person& enemy, int dmg) {
	if (enemy._armor == 1)
		_armor = 0;
	else
		enemy._hp -= dmg;
	if (enemy._hp <= 0)
		cout << "����" << "\n";
	rise_mana(enemy);
}

//������� ��������� ����� ����
void Person::rec_poison_dmg() {
	if (_time_poison != 0) {
		_hp -= 5;
		_time_poison--;
	}
}

//������� ��������� ����� �������������
void Person::rec_bleed_dmg() {
	if (_time_bleed != 0) {
		_hp -= 5;
		_time_bleed--;
	}
}