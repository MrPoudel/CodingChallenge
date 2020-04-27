#include <iostream>
#include<typeinfo>  // Needed for typeid.

using namespace std;

class Test{
private:
	int age;
public:
	Test():age(0){

	}
};


int main() {

	string value;

	cout << typeid(value).name() << endl;

	Test test;
	cout << typeid(test).name() << endl;

	decltype(value) name = "Bob";
	cout << name << endl;

	cout << "Exited successfully!" << endl;

	return 0;
}
