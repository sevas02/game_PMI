#include "Checkers.h"
#include <iostream>
using namespace std;


int heroes_num(){
	int heroes_num;
	cin >> heroes_num;
	while (cin.fail() || heroes_num > 3 || heroes_num < 0){
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Пожалуйста, введите корректное значение (кол-во героев не превышет 3):\n";
		cin >> heroes_num;
	}
	return heroes_num;
}

int check_idx(int max_num) {
	int idx;
	cin >> idx;
	while (cin.fail() || idx > max_num || idx <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Пожалуйста, введите корректное значение:\n";
		cin >> idx;
	}
	return idx;
}