#ifndef MENU_H
#define MENU_H

#include <Windows.h>
#include "Person.h"
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "List.h"
#include "text_color.h"
using namespace std;

void print(list<Person*>& lst);

void choose_light_person(list<Person*>& light_warriors, int num);

void choose_dark_person(list<Person*>& dark_warriors, int num);

int get_idx_dark(Person* hero);

int get_idx_light(Person* hero);

//��� ������ ���������
void dark_persons_step(list<Person*>& dark_warriors, list<Person*>& light_warriors);

//��� �������� ���������
void light_persons_step(list<Person*>& dark_warriors, list<Person*>& light_warriors);

//�������� ����� �� ��������
void check_person_hp(list<Person*>& heroes);

//�������� ���������� �� ������������
void check_person_time_bleed(list<Person*>& heroes);

//�������� ���������� �� ����������
void check_person_time_poison(list<Person*>& heroes);

#endif
