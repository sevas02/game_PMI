#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Person.h"
#include <exception>
using namespace std;

template <class T>
class node {
private:
	T _value;
	node<T>* _next;
	node<T>* _prev;
	node(T k) { _value = k; _next = _prev = 0; }
public:
	node<T>* next() { return _next; }
	T value() { return _value; }
	void set_value(T val) { _value = value; }
	template <class T1> friend class list;
};

template <class T>
class list {
private:
	node<T>* _first;
	node<T>* _last;
	int _size;
public:
	list() { _first = 0, _last = 0, _size = 0; }
	~list();

	node<T>* first() { return _first; }
	node<T>* last() { return _last; }
	int size() { return _size; }

	node<T>* create_node(T info);
	void push_front(T value);
	void push_back(T value);
	bool delete_element(int);
	bool delete_last();
	bool delete_front();
	T find_value(int idx);
};

template <class T> 
list<T>::~list() {
	if (_first == 0)
		return;
	node<T>* curr = _first;
	node<T>* elem = _first->_next;
	while (elem != 0) {
		delete curr;
		curr = elem;
		elem = curr->_next;
	}
	delete curr;
	_first = 0;
}

//Метод создания узла
template <class T> 
node<T>* list<T>::create_node(T info) {
	node<T>* el = new node<T>{info};
	el->_value = info;
	el->_next = 0;
	el->_prev = 0;
	return el;
}

//Метод добавления узла в начало списка
template <class T> 
void list<T>::push_front(T value) {
	node<T>* new_el = create_node(value);
	if (_size == 0) {
		_first = new_el;
		_last = _first;
		_size++;
		return;
	}
	if (_first != 0) {
		new_el->_next = _first;
		_first->_prev = new_el;
		_first = new_el;
		_size++;
		return;
	}
	if (_last == 0)
		_last = new_el;
	_size++;
}

//Метод добавления узла в конец списка
template <class T> 
void list<T>::push_back(T value) {
	node<T>* new_el = create_node(value);
	if (_size == 0) {
		_first = new_el;
		_last = _first;
		_size++;
		return;
	}
	if (_last != 0) {
		new_el->_prev = _last;
		_last->_next = new_el;
		_last = _last->_next;
		_size++;
		return;
	}
	if (_last == 0)
		_last = new_el;
	_size++;
}

//Метод удаления узла с конца списка
template <class T> 
bool list<T>::delete_last() {
	if (_size == 0)
		return 0;
	node<T>* new_elem = _last;
	_last = _last->_prev;
	delete new_elem;
	_size--;
	return 1;
}

//Метод удаления узла сначала
template <class T> 
bool list<T>::delete_front() {
	if (_size == 0)
		return 0;
	node<T>* new_elem = _first;
	_first = _first->_next;
	delete new_elem;
	_size--; 
	return 1;
}

//Метод удаления узла 
template <class T> 
bool list<T>::delete_element(int idx) {
	if (idx > _size)
		return 0;
	node<T>* elem = _first;
	while (idx > 0) {
		elem = elem->_next;
		idx--;
	}
	if (elem->_prev == 0) {
		if (_size > 1)
			elem->_next->_prev = 0;
		_first = elem->_next;
	}
	else
		elem->_prev->_next = elem->_next;
	delete elem;
	_size--;
	return 1;
}

//Реализация поиска в списке
//ВНИМАНИЕ ЕСЛИ ИНДЕКС БОЛЬШЕ РАЗМЕРА,
//КИДАЕТСЯ ИСКЛЮЧЕНИЕ, НАДО ЛОВИТЬ
template <class T> 
T list<T>::find_value(int idx) {
	if (idx > _size)
		throw 1;
	node<T>* elem = _first;
	while (idx > 0) {
		elem = elem->_next;
		idx--;
	}
	return elem->_value;
}
#endif
