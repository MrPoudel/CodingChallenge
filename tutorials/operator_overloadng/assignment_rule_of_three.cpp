// Rule of three in C++
// If you implement any one of the following in C++ class, the you must implement the rest of two.
// 1. Destructor
// 2. Copy constructor
// 3. Assignment operator

#include <iostream>

using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test():id(0), name(""){

	}

	Test(int id, string name): id(id), name(name){

	}

	~Test(){
		// cout << "Object destroyed" << endl;
	}

	void print(){
		cout << id << ":" << name << endl;
	}

	const Test& operator=(const Test &other){
		cout << "Assignement operator runnig" << endl;

		id = other.id;
		name = other.name;

		return *this;
	}

	Test(const Test &other){
		cout << "Copy constructor running" << endl;
//		id = other.id;
//		name = other.name;
		*this = other; // This will again call the assignment operator to assign the value.
	}
};


int main() {

	Test test1(10, "Mike");
	test1.print();

	Test test2(20,"Bob");
	test2=test1;
	test2.print();

	Test test3;
	//test3=test1;
	test3.operator=(test2);
	test3.print();

	cout << endl;

	// Copy initialization. Implicit copy constructor
	// If you declare the object and directly assign the value at the same time then it uses the copy constructor not the assignment operator.
	Test test4 = test1;
	test4.print();

	cout << "Exited successfully!" << endl;


	return 0;
}

