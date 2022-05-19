#ifndef STACK
#define STACK
#include "Person.h"

struct step {
	Person l_pers, r_pers;
	void func();
};

struct Node {
	Node* prev;
	int x;
	Node() { prev = nullptr; x = 0; }
	Node(Node* a, int b) { prev = a; x = b; }
};

class stack {
private:
	Node* Head = nullptr;
	int Size = 0;

public:
	int size(); //возвращает размер стека
	void push(int p); //закидывает элемент х в стек
	int back(); //возвращает значение последнего элемента стека
	int pop(); //удаляет последний элемент стека
	void clear(); //очистка стека
};

//возвращает размер стека
int stack::size() {
	return Size;
}

//закидывает элемент х в стек
void stack::push(int p) {
	Node* NewHead = new Node(Head, p);
	Head = NewHead;
	Size++;
}

//возвращает значение последнего элемента стека
int stack::back() {
	if (Size) { return Head->x; }
	else { return 0; }
}

//удаляет последний элемент стека
int stack::pop() {
	if (Size) {
		int x = Head->x;
		Node* NewHead = Head->prev;
		delete Head;
		Head = NewHead;
		Size--;
		return x;
	}
	else {
		return 0;
	}
}

//очистка стека
void stack::clear() {
	while (Size > 0) {
		Node* NewHead = Head->prev;
		delete Head;
		Head = NewHead;
		Size--;
	}
}

#endif
