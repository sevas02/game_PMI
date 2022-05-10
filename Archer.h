#ifndef ARCHER
#define ARCHER

#include <vector>
#include "Person.h"
using namespace std;

class Archer : Person {
public:
	//конструктор
	Archer();

	//супервыстрел 
	void super_arrow_shot(Person& enemy);

	//град стрел (удар по всем противникам)
	void hail_of_arrows(vector<Person>& enemies);

	//деструктор
	~Archer();
};

#endif
