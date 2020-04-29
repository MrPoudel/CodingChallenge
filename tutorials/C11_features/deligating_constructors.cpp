#include <iostream>

using namespace std;

class Parent {
	int dogs{5};
	string text{"Hello"};
public:
	Parent(): Parent("Hello"){ // In C++98 we can not call another constructor from within a constructor.
		cout << "No parameter parent constructor." << endl;
	}

	Parent(string text){
			this->text = text;
			cout << "string parent constructor." << endl;
	}
};

class Child: public Parent {
public:
	Child() {  // We can define this constructor as: Child() = default;

		cout << "No parameter child constructor." << endl;

	}
};

int main() {

	Parent parent("Hello");
	Child child;

	//cout << parent.dogs << endl;

	cout << "Exited successfully!" << endl;

	return 0;
}
