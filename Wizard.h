#ifndef WIZRAD
#define WIZARD
#include <vector>
#include "Person.h"
using namespace std;

class Wizard : public Person {
private:
	//�������� ��� ������������� ����� (30% �� ������������� �������� ���������)
	int val_heal = 0.3;
	//���� ��� ������������ �������� (40% �� ��������)
	int val_fire_dmg = 0.4;
public:
	//�����������
	Wizard();

	//�������������� �������� ��������
	void super_healing(Person &kent);

	//�������� ����� (� ������������ 20% ��������� ���� ���������� �����)
	void super_fire_punch(vector<Person>& enemies);

	//����������
	~Wizard();
};
#endif