#ifndef MENU_H
#define MENU_H

#include "Person.h"
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
#include "List.h"
using namespace std;

void choose_light_person(list<Person*>& light_warriors, int num);

void choose_dark_person(list<Person*>& dark_warriors, int num);

int det_person_dark(Person* hero);

int det_person_light(Person* hero);


#endif
