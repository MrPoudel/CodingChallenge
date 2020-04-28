// In lambda capture, objects are captured by passing `this` keyword and they are always captured by reference.
#include <iostream>

using namespace std;

class Test{
private:
	int one{1};
	int two{2};
public:
	void run (){
		int three{3};
		int four{4};

		// this will also work
		//auto pLambda = [&, this](), it means all the variables by reference and this object instance as always by reference.
		auto pLambda = [three, this,  four](){ // this means it is captured by reference so we can modify the value of one.
			one = 111;
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four << endl;
		};

		pLambda();
	}
};


int main() {

	Test test;
	test.run();


	cout << "Exited successfully!" << endl;

	return 0;
}
