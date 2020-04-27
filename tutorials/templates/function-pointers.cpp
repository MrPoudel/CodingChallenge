#include <iostream>

using namespace std;

void test(int value){
	cout << "Hello:" << value << endl;
}

int main() {

	test(11);

	// using function pointer
	cout << endl;

	void (*ptr)(int);
	ptr = &test; //test
	(*ptr)(7); //ptr();

	cout << "Exited successfully!" << endl;
	return 0;
}
