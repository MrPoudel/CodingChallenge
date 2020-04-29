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
	Sister sister;


	Parent *ppb = &brother;

	Sister *pbb = reinterpret_cast<Sister*>(ppb); // literally any cast is possible...
	//even less checking than in the static_cast
	// If some situation arises where you genuinely need to cast one type of pointer to completely another type of 
	// pointer and if dynamic cast and static cast doesn't work then in this situation reinterpret cast can be used.

	if(pbb == nullptr) {
		cout << "Invalid cast" << endl;
	}
	else{
		cout << pbb << endl;
	}


	cout << "Exited successfully!" << endl;

	return 0;
}

