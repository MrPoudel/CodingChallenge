#include <iostream>


using namespace std;

class Parent {
public:
	void speak(){
		cout << "Parent!" << endl;
	}

};

class Brother: public Parent{

};

class Sister: public Parent{

};


int main() {

	Parent parent;
	Brother brother;

	float value = 3.23;
	cout << (int)value << endl; // C style
	cout << int(value) << endl; // C++
	cout << static_cast<int>(value) << endl; // C++

	Parent *pp = &brother; // Polymorphism
	//Brother *bp = &parent; // Won't work
	Brother *bp = static_cast<Brother*>(&parent); // however unsafe!

	cout << bp << endl;

	Brother *pbb = &brother;
	Brother *pbb1 = static_cast<Brother*> (pp); // Still error prone...No run time, only compile time checking !

	cout << pbb1 << endl;

	Parent &&p = Parent(); // rvalue reference
	Parent &&p7 = static_cast<Parent&&> (parent);
	p7.speak();



	cout << "Exited successfully!" << endl;

	return 0;
}

