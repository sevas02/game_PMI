#ifndef ARCHER
#define ARCHER

#include <vector>
#include "Person.h"
using namespace std;

class Archer : Person {
public:
	//конструктор стрелка
	Archer();

	//супервыстрел стрелой с последующим кровотечением у противника
	void super_arrow_shot(Person& enemy);

	//град стрел (удар по всем противникам)
	void hail_of_arrows(vector<Person>& enemies);

	//деструктор стрелка
	~Archer();
};

#endif
