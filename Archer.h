#ifndef ARCHER
#define ARCHER

#include "Person.h"
#include "List.h"
using namespace std;

class Archer : public Person {
public:
	//конструктор стрелка
	Archer();

	//конструктор копирования
	Archer(Person &arch);

	//обычная атака
	void simple_attack(Person* enemy);

	//супервыстрел стрелой с последующим кровотечением у противника
	void super_arrow_shot(Person* enemy);

	//град стрел (удар по всем противникам)
	void hail_of_arrows(list<Person*>& enemies);

	//выбор способности
	void choose_ability(list<Person*>& enemies);

	//деструктор стрелка
	~Archer();
};

#endif
