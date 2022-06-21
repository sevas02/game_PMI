#ifndef MOTION_H
#define MOTION_H

#include "Person.h"
#include "List.h"
#include <iostream>
using namespace std;

class motion {
private:
	list<Person*> _light_wars;
	list<Person*> _dark_wars;
public:
	//ФУНКЦИИ КОПИРВАНИЯ ПЕРСОНАЖЕЙ (ДЛЯ ДАЛЬНЕЙШЕГО ОТКАТА)
	void copy_light_list2list(list<Person*>&);
	void copy_dark_list2list(list<Person*>&);
	void copy_list2list(list<Person*>& light_wars, list<Person*>& dark_wars);

	//ФУНКЦИИ ВОЗВРАТА СОХРАНЕННЫХ ЗАЧЕНИЙ ПЕРСОНАЖЕЙ (ДЛЯ ОТКАТА)
	void return_light_list2list(list<Person*>&);
	void return_dark_list2list(list<Person*>&);
	void return_list2list(list<Person*>& dark_wars, list<Person*>& light_wars);
};
#endif
