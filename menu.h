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

//функция вывода персонажей из листа
void print(list<Person*>& lst);

//функция выбора персонажа темной стороны
void choose_light_person(list<Person*>& light_warriors, int num);

//функция выбора персонажа светлой стороны
void choose_dark_person(list<Person*>& dark_warriors, int num);

//функция которая определяет персонажа темных сил 
int get_idx_dark(Person* hero);

//функция которая определяет персонажа светлых сил 
int get_idx_light(Person* hero);

//ход тёмного персонажа
void dark_persons_step(list<Person*>& dark_warriors, list<Person*>& light_warriors);

//ход светлого персонажа
void light_persons_step(list<Person*>& dark_warriors, list<Person*>& light_warriors);

//проверка живой ли персонаж
void check_person_hp(list<Person*>& heroes);

//проверка персонажей на кровотечение
void check_person_time_bleed(list<Person*>& heroes);

//проверка персонажей на отравление
void check_person_time_poison(list<Person*>& heroes);

#endif
