#include <Windows.h>
#include "Wizard.h"
#include "Archer.h"
#include "Monsters.h"
#include "Warrior.h"
using namespace std;

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	Wizard *mag = new Wizard();
//	Archer luk;
//	Warrior voin;
	Person *def_mnstr = new Monster_base();
	Person *bet_mnstr = new Monster_boss();
	Person *boss_mnstr = new Monster_base_better();

	vector <Person*> Light = { mag };
	vector <Person*> Dark = { def_mnstr, bet_mnstr, boss_mnstr };
	mag->deal_dmg(def_mnstr, mag->dmg());
	mag->deal_dmg(bet_mnstr, mag->dmg());
	mag->deal_dmg(boss_mnstr, mag->dmg());
	cout << def_mnstr->hp() << '\n';
	cout << bet_mnstr->hp() << '\n';
	cout << boss_mnstr->hp() << '\n';
	for (int i = 0; i < 4; i++)
		mag->super_fire_punch(Dark);
	cout << *mag;
	/*
	cout  << "Монстер атакует Лучника\n";
	def_mnstr.deal_dmg(luk, def_mnstr.dmg());
	cout << "Хп Лучника после атаки Монстра = " << luk.hp() << "\n";
	cout << "Маг хиллит Лучника\n";
	mag.super_healing(luk);
	cout << "Хп Лучника после хилла Мага = " << luk.hp() << "\n";
	cout << "Маг использует способность <Огненная удача>\n";
	for (int i = 0; i < 4; i++)
		mag.super_fire_punch(Dark);
	cout << "Лучник использует способность <Супервыстрел> по Улучшенному монстру\n";
	luk.super_arrow_shot(bet_mnstr);
	cout << "Хп Ул. монстра после атаки лучника = " << bet_mnstr.hp() << "\n";
	cout << "Лучник использует способность <Град стрел>\n";
	luk.hail_of_arrows(Dark);
	for (int i = 0; i < Dark.size(); i++) {
		cout << "Хп монстра № " << i << "после атаки лучника " <<
			Dark[i].hp() << "\n";
	}*/
	delete def_mnstr;
	delete boss_mnstr;
	delete bet_mnstr;
	return 0;
}