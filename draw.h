#ifndef DRAW_H
#define DRAW_H
#include<GL/glut.h>
#include"Person.h"
#include "text_color.h"

void display();

void myinit();

void SpecKeyboard(int key, int x, int y);

//�������������� ��������
void hello();

//���������� �������
void draw_side(list<Person*>& persons, int side, int num_heroes);

//������� ����������� hp 
void changes_hp(Person& pers, int side, int del, int j);

#endif DRAW_H