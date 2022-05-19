#include "Monsters.h"
using namespace std;

//Конструктор для базового монстра
Monster_base::Monster_base() {
	_hp = 100;
	_max_hp = 100;
	_dmg = 10;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Порося";
}

//функция атаки монстров
void Monster_base::Monster_attack(Person& enemy) {
	srand(time(0));
	deal_dmg(&enemy, _dmg);
	int num = 1 + rand() % 10;
	//урон нанесется с 20% шансом
	if (num <= 2) {
		//3 - число ходов
		enemy.app_time_poison(3);
		enemy.rec_poison_dmg();
	}
	null_mana();
}

//Деструктор для базового монстра
Monster_base::~Monster_base() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}


//Конструктор для монстра босса
Monster_boss::Monster_boss() {
	_hp = 200;
	_max_hp = 200;
	_dmg = 20;
	_mana = 0;
	_armor = 1;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "БОРОВ";
}

//Супер атака босса монстра
void Monster_boss::Monster_boss_sup_attack(std::vector<Person> enemies) {
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].app_time_poison(5);
		enemies[i].rec_poison_dmg();
	}
	null_mana();
}

//Деструктор для монстра босса
Monster_boss::~Monster_boss() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
} 

//конструктор для монстра (чуть лучше базового)
Monster_base_better::Monster_base_better() {
	_hp = 120;
	_max_hp = 120;
	_dmg = 15;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Свин";
}

//функция суперудара
void Monster_base_better::Monster_sup_attack(Person& enemy) {
	deal_dmg(&enemy, _dmg / 2);
	//5 - число ходов
	enemy.app_time_poison(5);
	enemy.rec_poison_dmg();
}

//деструктор для монстра (чуть лучше базового)
Monster_base_better::~Monster_base_better() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}

Monster_vampire::Monster_vampire() {
	_hp = 60;
	_max_hp = 60;
	_dmg = 30;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "Вампир";
}

void Monster_vampire::vampire_attack(Person& enemy) {
	deal_dmg(&enemy, _dmg / 2);
	//5 - число ходов
	enemy.app_time_bleed(5);
	enemy.rec_bleed_dmg();
	//в дальнейшем планируется сделать пополнение здоровья в течение игры а не сразу
	_hp += 25;
	null_mana();
}

Monster_vampire::~Monster_vampire() {
	_hp = 0;
	_max_hp = 0;
	_dmg = 0;
	_mana = 0;
	_armor = 0;
	_time_bleed = 0;
	_time_poison = 0;
	_name = "";
}