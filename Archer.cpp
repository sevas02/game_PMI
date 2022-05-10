#include <iostream>
#include "Archer.h"
#include "Person.h"
using namespace std;

//конструктор стрелка
Archer::Archer() {
	_hp = 80;
	_dmg = 15;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}

//супервыстрел стрелой с последующим кровотечением у противника
void Archer::super_arrow_shot(Person& enemy) {

	//урон от стрелы увеличивается
	int temp_dmg = _dmg * 1.75;

	deal_dmg(enemy, temp_dmg);
	//обнуление только что потраченной маны
	null_mana();

	//супервысрел дает последствия (кровотечение противника)
	enemy.app_time_bleed(2);
	enemy.rec_bleed_dmg();
}

//град стрел (удар по всем противникам)
void Archer::hail_of_arrows(vector<Person>& enemies) {

	//урон от стрел чуть уменьшается
	int temp_dmg = _dmg * 0.75;

	for (int i = 0; i < enemies.size(); i++) {
		deal_dmg(enemies[i], temp_dmg);

		//srand - инициализация генератора случайных чисел
		//time - возвращает текущее календарное время системы
		srand(time(0));
		int number = rand() % 10; 

		//с вероятностью 10% противник может получить отравленную стрелу
		if (number == 7) {
			enemies[i].app_time_poison(3);
			enemies[i].rec_poison_dmg();
		}
	}
	//обнуление только что потраченной маны
	null_mana();
}

//деструктор стрелка
Archer::~Archer() {
	_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
}
