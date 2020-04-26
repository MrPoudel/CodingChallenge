#include "Complex.h"

using namespace caveofprogramming;

int main() {

	Complex c1(2, 3);
	Complex c2 = c1; // Initialization copy.
	Complex c3;
	c3 = c1; // Assignement.

	cout << c1 << c2 << c3;


	cout << "Exited successfully!" << endl;
	return 0;
}

//Output
//Copied
//Assignment
//Parameterless!
//Assignment
//(2,3)
//(2,3)
//(2,3)
//Exited successfully!
