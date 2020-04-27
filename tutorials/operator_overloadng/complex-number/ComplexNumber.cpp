
#include "Complex.h"

using namespace std;
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

	if (c1 == c2){
		cout << "Equal" << endl;
	}
	else{
		cout << "Not Equal" << endl;
	}

	cout << endl;

	if (c1 != c4){
			cout << "Not Equal" << endl;
		}
		else{
			cout << "Equal" << endl;
		}

	cout << "Conjugate is:" << *c1 << endl;

	cout << "Exited successfully!" << endl;
	return 0;
}
