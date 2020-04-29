#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

int add(int a, int b, int c){
	cout << a << "," << b << "," << c << endl;
	return a + b + c;
}


int run(function<int(int, int)> func) {
	return  func(7,3);
}

int main() {

	auto calculate = bind(add, 3, 4, 5);
	cout << calculate() << endl;

	auto calculate2 = bind(add, _1, _2, _3);
	cout << calculate2(10, 20 ,30) << endl;

	auto calculate3 = bind(add, _2, _3, _1);
	cout << calculate3(10, 20 , 30) << endl; // first parameter to add _2 --> 20, _3 -> 30 and _1 -> 10.

	// You can combine the placeholders and arguments.
	auto calculate4 = bind(add, 4, _3, _1);
	cout << calculate4(10, 20, 30) << endl; // 10 has no meaning here.

	// Anoher example
	auto calculate5 = bind(add, _1, _3, 1000);
	cout << calculate5(10, 333, 9) << endl; // Should be 1019

	// Anoher example
	auto calculate6 = bind(add, _2, _1, 1000);
	cout << calculate6(10, 9) << endl; // Should be 1019

	// Final demo
	auto calculate100 = bind(add, _2, 100, _1);
	//cout << calculate100(10, 20) << endl;

	cout << run(calculate100) << endl;


	cout << "Exited successfully!" << endl;

	return 0;
}

