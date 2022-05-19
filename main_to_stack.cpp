#include <iostream>
#include "Stack.h"

using namespace std;

//проверка стека 
int main() {
	stack st, st_delete;
	st.push(6);
	st.push(1);
	st.push(8);
	st.push(3);
	cout << st.size() << endl;
	cout << st.back() << endl;
	st.pop();
	cout << st.back() << endl;
	st.clear();
	cout << st.size() << endl;
	st.push(8);

}