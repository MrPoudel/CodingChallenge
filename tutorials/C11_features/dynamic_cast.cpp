#include <iostream>

using namespace std;

class Parent {
public:
	virtual void speak(){
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


	Parent *ppb = &parent;

	Brother *pbb = dynamic_cast<Brother*>(ppb);

	if(pbb == nullptr) {
		cout << "Invalid cast" << endl;
	}
	else{
		cout << pbb << endl;
	}

	// Makes sense!
	Parent *ppb1 = &brother; // Polymorphism
	Brother *pbb1 = dynamic_cast<Brother*>(ppb1);

		if(pbb1 == nullptr) {
			cout << "Invalid cast" << endl;
		}
		else{
			cout << pbb1 << endl;
		}

	cout << "Exited successfully!" << endl;

	return 0;
}

