#include <iostream>

using namespace std;


int main() {

	int one = 1;
	int two = 2;
	int three = 3;

	//capture onw and two by values
	[one, two](){ cout << one << "," << two << endl; }();

	// capture all local variables by value.
	[=](){ cout << one << "," << two << "," << three << endl; }();

	// capture all local variables by value but capture three by reference.
	[=, &three](){ three = 7; cout << one << "," << two << "," << three << endl; }();

	cout << three << endl;

	// capture all local variables by reference.
	[&](){ three = 7; two = 9; cout << one << "," << two << "," << endl; }();

	cout << two << endl;


	// capture all local variables by reference, but two and three by value.
	[&, two, three](){ one = 100; cout << one << "," << two << "," << endl; }();

	cout << one << endl;


	cout << "Exited successfully!" << endl;

	return 0;
}
