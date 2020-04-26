
#include <iostream>
#include <ostream>

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

	friend ostream& operator<<(ostream& out, const Test& other);
};

ostream& operator<<(ostream& out, const Test& other){
		out << other.id << ":" << other.name;
		return out;
	}


int main() {

	Test test1(10, "Mike");
	cout << test1 << endl;
	//test1.print();



	cout << "Exited successfully!" << endl;


	return 0;
}
