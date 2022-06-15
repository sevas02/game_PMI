#ifndef STACK_H
#define STACK_H

#include <exception>
#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
struct note {
	T val;
};

template <class T>
class Stack_arr {
private:
	note<T>* arr;
	const unsigned int size;
	int top; //������ �������� ��������
public:
	//����������� �����
	Stack_arr(const unsigned int maxSize) :
		size(maxSize), top(0), arr(new note<T>[maxSize]) {}

	//���������� �����
	~Stack_arr() { delete[] arr; }

	//���������� ��������� ������
	ostream& operator << (ostream& os, const arr& stk) {
		os << arr.val;
		return os;
	}

	//������� ���������� ��������
	void push(const T);

	//������� �������� ��������
	T pop();

	//���������� ������� �������
	T GetTop() const;

	//������ ������
	unsigned int sizeStack() const;

	//���������� ����
	void printStack();
};

template <class T>
void Stack_arr<T>::push(const T newElement) {
	try {
		if (top >= size)
			throw 1;
		if (top == 0) {
			arr[top].val = newElement;
			top++;
		}
		else if (arr[top - 1].curMax > newElement) {
			arr[top].val = newElement;
			top++;
		}
		else {
			arr[top].val = newElement;
			top++;
		}
	}
	catch (int i) {
		cout << "������ �" << i << " ������������ �����\n";
	}
}

template <class T>
T Stack_arr<T>::pop() {
	try {
		if (top <= 0)
			throw 2;
		T elem = arr[top].val;
		top--;
		return elem;
	}
	catch (int i) {
		cout << "������ �" << i << " � ����� ������ ��� ���������\n";
	}
}

template <class T>
T Stack_arr<T>::GetTop() const {
	try {
		if (top <= 0)
			throw 3;
		return arr[top - 1].val;
	}
	catch (int i) {
		cout << "������ �" << i << " ���� ����!\n";
	}
}


template <class T>
unsigned int  Stack_arr<T>::sizeStack() const {
	return top;
}

template <class T>
void Stack_arr<T>::printStack() {
	for (int idx = top - 1; idx >= 0; idx--)
		cout << "|" << setw(4) << arr[idx] << endl;
}

#endif // STACK_H
