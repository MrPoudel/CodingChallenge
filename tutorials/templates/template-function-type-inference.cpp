#include <iostream>

using namespace std;

template<typename T>
void print(T n){
	cout << "Template version:" << n << endl;
}

void print(int value){
	cout << "Non-template version:" << value << endl;
}

template<typename T>
void show(T n){
	cout << T() << endl;
}

int main() {

	print<string>("Hello");
	print<int>(7);
	print(11);
	print<>(13);

	print("Hi there"); // C++ loads the arguments and infers what type of argument it is!

	show<double>(1);
    cout << "Integer constructor:" <<  int() << endl; // What is this?


	cout << "Exited successfully!" << endl;
	return 0;
}
