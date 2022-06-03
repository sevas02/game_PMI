#include "Checkers.h"
#include <iostream>
using namespace std;

int heroes_num(){
	int heroes_num;
	cin >> heroes_num;
	while (cin.fail() || heroes_num > 3 || heroes_num < 0){
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> heroes_num;
	}
	return heroes_num;
}

int idx(int max_num) {
	int idx;
	cin >> idx;
	while (cin.fail() || idx > max_num || idx <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> idx;
	}
	return idx;
}