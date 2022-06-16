#ifndef STACK_H
#define STACK_H

#include <exception>
#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
	T* arr;
	const unsigned int size;
	int top; //Индекс верхнего элемента
public:
	//Конструктор стека
	Stack(const unsigned int maxSize) :
		size(maxSize), top(0), arr(new T[maxSize]) {}

	//Деструктор стека
	~Stack() { delete[] arr; }

	//Функция добавления элемента
	void push(const T);

	//Функция удаления элемента
	T pop();

	//Посмотреть верхний элемент
	T GetTop() const;

	//Узнать размер
	unsigned int sizeStack() const;

	//Напечатать стэк
	void printStack();
};

//Функция добавления элемента
template <class T>
void Stack<T>::push(const T newElement) {
	if (top >= size)
		throw 1;
	arr[top] = newElement;
	top++;
}

//Функция удаления элемента
template <class T>
T Stack<T>::pop() {
	if (top <= 0)
		throw 2;
	T elem = arr[top];
	top--;
	return elem;

}

//Посмотреть верхний элемент
template <class T>
T Stack<T>::GetTop() const {
	if (top <= 0)
		throw 3;
	return arr[top - 1];
}

//Узнать размер
template <class T>
unsigned int  Stack<T>::sizeStack() const {
	return top;
}

//Напечатать стэк
template <class T>
void Stack<T>::printStack() {
	for (int idx = top - 1; idx >= 0; idx--)
		cout << "|" << setw(4) << arr[idx] << endl;
}

#endif // STACK_H