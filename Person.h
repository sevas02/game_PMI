#ifndef PERSON
#define PERSON

class Person {
protected:
	int _hp; //��������
	int _dmg; //����
	double _mana; //����
	bool _armor; //���
	int _time_bleed; //����� �����������
	int _time_poison; //����� ����������
public:
	//�������
	int hp() { return _hp; }
	int dmg() { return _dmg; }
	double mana() { return _mana; }
	bool armor() { return _armor; }
	int time_bleed() { return _time_bleed; }
	int time_poison() { return _time_poison; }

	//�������
	void Set_hp(int hp) { _hp = hp; }
	void Set_dmg(int dmg) { _dmg = dmg; }
	void Set_mana(double mana) { _mana = mana; }
	void Set_armor(bool armor) { _armor = armor; }
	void Set_time_bleed(int time_bleed) { _time_bleed = time_bleed; }
	void Set_time_poison(int time_poison) { _time_poison = time_poison; }

	//������� ��� ���������� ����� � ��������� ���������� � ������������
	void app_time_bleed(int app_time_bleed) { _time_bleed += app_time_bleed; }
	void app_time_poison(int app_time_poison) { _time_poison += app_time_poison; }

	//���������� ����
	void rise_mana(Person enemy);

	//��������� �����
	void deal_dmg(Person& enemy, int dmg);

	//��������� ����� (recieve)
	void rec_dmg(Person enemy) { _hp -= ((_armor == true) ? _armor = false : _dmg); }

	//��������� �� (recieve)
	void rec_hp(int val) { _hp += val; }

	//��������� ����
	void null_mana() { _mana = 0; }

	//��������� �����
	void recieve_armor() { _armor = true; }

	//��������� ����� �� ����������
	void rec_poison_dmg();

	//��������� ����� �� ������������
	void rec_bleed_dmg();
};

#endif
