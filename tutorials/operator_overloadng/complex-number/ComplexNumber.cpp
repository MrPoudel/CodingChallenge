
#include "Complex.h"

using namespace caveofprogramming;

int main() {

	Complex c1(3,4);


	cout << c1 << endl;

	cout << (c1+c1+c1) << endl;

	Complex c2 = c1;
	Complex c3(3, 3);
	Complex c4;
	c4 = c3;

	cout << c1+c2+c3+c4 << endl;

	cout << c1 + 5 << endl;

	cout << 5 + c1 << endl;

	cout << 5 + c1 + 5 + 5 + c1 << endl;

	cout << "Exited successfully!" << endl;
	return 0;
}

//Output
//(3,4)
//
//(9,12)
//
//Copied
//Assignment
//Parameterless!
//Assignment
//(12,14)
//
//(8,4)
//
//(8,4)
//
//(21,8)
//
//Exited successfully!
