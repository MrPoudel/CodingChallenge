#include <iostream>

using namespace std;

class Test {

};

template<typename T>
void call(T &&arg){
	//check(static_cast<T>(arg));
	check(forward<T>(arg)); // both are same
}

void check(Test &test){
	cout << "lvalue" << endl;
}

void check(Test &&test){
	cout << "rvalue" << endl;
}

int main() {

	Test test;
	//auto &&t = Test(); // reference collasping in C++11

	call(Test()); // passing rvalue
	call(test); // passing lvalue


	cout << "Exited successfully!" << endl;

	return 0;
}

