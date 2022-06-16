#ifndef WIZARD
#define WIZARD
#include <vector>
#include "Person.h"
using namespace std;

class Wizard : public Person {
private:
	//Значение при использовании хилла (30% от максимального здоровья союхзника)
	double val_heal = 0.3;
	//Урон при срабатывании пассивки (40% от базового)
	double val_fire_dmg = 0.4;
public:
	//Конструктор
	Wizard();

	//Конструктор копирования
	Wizard(Person &wizrd);

	//Восстановление здоровья выбранному союзнику
	void super_healing(Person* kent);

	//Огненная удача (с вероятностью 20% наносится удар рандомному врагу)
	void super_fire_punch(list<Person*>& enemies);

	//Выбор способности
	void choose_ability(list<Person*>& enemies, list<Person*>& kents);

	//Деструктор
	~Wizard();
};
#endif