#include <iostream>

using namespace std;

void testGreet(void (*greet)(string)){
	greet("Bob");
}

void runDivide(double (*divide)(double a, double b)){
	auto rval = divide(9,3);
	cout << rval << endl;
}


int main() {

	auto pGreet = [](string name){ cout << "Hello, " << name <<  endl; };
	pGreet("MrPoudel");

	testGreet(pGreet);

	auto pDivide = [](double a, double b) -> double {
		if(b == 0){
			return 0; // if we cast it to double we don't need a trailing return type syntax.
		}
		return a/b;
	};

	cout << pDivide(10.0, 5.0) << endl;
	cout << pDivide(10.0, 0) << endl;

	runDivide(pDivide);

	cout << "Exited successfully!" << endl;

	return 0;
}
