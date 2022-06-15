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
	int top; //индекс верхнего элемента
public:
	//конструктор стека
	Stack(const unsigned int maxSize) :
		size(maxSize), top(0), arr(new T[maxSize]) {}

	//деструктор стека
	~Stack() { delete[] arr; }

	//функция добавления элемента
	void push(const T);

	//функция удаления элемента
	T pop();

	//посмотреть верхний элемент
	T GetTop() const;

	//узнать размер
	unsigned int sizeStack() const;

	//напечатать стэк
	void printStack();
};

template <class T>
void Stack<T>::push(const T newElement) {
	if (top >= size)
		throw 1;
	arr[top] = newElement;
	top++;
}

template <class T>
T Stack<T>::pop() {
	if (top <= 0)
		throw 2;
	T elem = arr[top];
	top--;
	return elem;

}

template <class T>
T Stack<T>::GetTop() const {
	if (top <= 0)
		throw 3;
	return arr[top - 1];
}


template <class T>
unsigned int  Stack<T>::sizeStack() const {
	return top;
}

template <class T>
void Stack<T>::printStack() {
	for (int idx = top - 1; idx >= 0; idx--)
		cout << "|" << setw(4) << arr[idx] << endl;
}

#endif // STACK_H