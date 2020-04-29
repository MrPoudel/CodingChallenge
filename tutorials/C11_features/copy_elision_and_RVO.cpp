#include <iostream>
#include <vector>

using namespace std;

class Test {
public:
	Test(){
		cout << "Constructor" << endl;
	}

	Test(int i) {
		cout << "parameterized constructor" << endl;
	}

	Test(const Test &other) {
		cout << "Copy constructor" << endl;
	}

	Test &operator=(const Test &other){
		cout << "assignment" << endl;
		return *this;
	}

	~Test(){
		cout << "destructor" << endl;
	}

	friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test){
		out << "Hello from test" << endl;
		return out;
}

Test getTest() {
	return Test();
}


int main() {

	Test test1 = getTest();
	cout << test1 << endl;

	cout << "Exited successfully!" << endl;

	return 0;
}

//Output : without : ‑fno‑elide‑constructors
//Constructor
//Hello from test
//
//Exited successfully!
//destructor

//**********************//
//        : with     : ‑fno‑elide‑constructors
//Constructor
//Copy constructor
//destructor
//Copy constructor
//destructor
//Hello from test
//
//Exited successfully!
//destructor

