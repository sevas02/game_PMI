#ifndef WIZARD
#define WIZARD
#include <vector>
#include "Person.h"
using namespace std;

class Wizard : public Person {
private:
	//значение при использовании хилла (30% от максимального здоровья союхзника)
	double val_heal = 0.3;
	//урон при срабатывании пассивки (40% от базового)
	double val_fire_dmg = 0.4;
public:
	//конструктор
	Wizard();

	//восстановление здоровья союзнику
	void super_healing(Person* kent);

	//огненная удача (с вероятностью 20% наносится удар рандомному врагу)
	void super_fire_punch(list<Person*>& enemies);

	//выбор способности
	void choose_ability(list<Person*>& enemies, list<Person*>& kents);

	//деструктор
	~Wizard();
};
#endif