#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test{
public:
	static int add(int a, int b, int c){
		cout << "From static" << endl;
		cout << a << "," << b << "," << c << endl;
		return a + b + c;
	}

	int non_static_add(int a, int b, int c){
			cout << "From non-static" << endl;
			cout << a << "," << b << "," << c << endl;
			return a + b + c;
	}
};

int run(function<int(int, int)> func) {
	return  func(7,3);
}

int main() {

	auto calculate = bind(&Test::add, _2, 100, _1);
	cout << run(calculate) << endl;

	Test test;
	auto non_static = bind(&Test::non_static_add,test,  _2, 100, _1);
	cout << run(non_static) << endl;

	cout << "Exited successfully!" << endl;

	return 0;
}

