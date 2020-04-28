#include <iostream>


using namespace std;

class Test{
	int id{3}; // int id = 3; //old style works as well.
	string name{"Mike"};
public:
	Test() = default;
	Test(const Test &other) = default; // If we want a copy constructor explicitly.
	Test &operator=(const Test &other) = default;
	Test(int id):id(id){}
	void print(){
		cout << id << ":" << name << endl;
	}
};

int main() {

    Test test;
    test.print();

    Test test1(77);
    test1.print();

    Test test2 = test1; // Copy constructor. // won't work if copy constructor is assigned to delete.
    test2 = test1; // Assignement operator.  // won't work if the assignment operator is assigned as delete.

	cout << "Exited successfully!" << endl;

	return 0;
}
