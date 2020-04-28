#include <iostream>

using namespace std;

void test(void (*pFunc)()){
	pFunc();
}


int main() {

	auto func = [](){ cout << "Hello" << endl; }; // storing an anonymous function to a variable called func.
	func();

	[](){ cout << "Hello" << endl; }(); // Can be called directly.

	test(func); // another way to pass a lambda function to another function.
	test([](){ cout << "Hello again!" << endl; });

	cout << "Exited successfully!" << endl;

	return 0;
}
