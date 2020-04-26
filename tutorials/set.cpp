//============================================================================
// Name        : Vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>  // Stores only the unique elements.
#include <string>


using namespace std;

class Test {
	int id;
	string name;

public:
	Test(): id(0), name(""){

	}
	Test(int id, string name): id(id), name(name){

	}

	void print() const{
		cout << id << ":" << name << endl;
	}

	bool operator<(const Test& other) const {
		return name < other.name;
	}
};

int main() {

	set <int> numbers;

	numbers.insert(50);
	numbers.insert(10);
	numbers.insert(30);
	numbers.insert(30);
	numbers.insert(40);


	for(set<int>:: iterator it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << endl;
	}


	set<int>::iterator itFind = numbers.find(305);

	if(itFind != numbers.end()){
		cout << "Found:" << *itFind << endl;
	}

	set<Test> tests;

	tests.insert(Test(11, "Julia"));
	tests.insert(Test(10, "Julia"));
	tests.insert(Test(30, "Mike"));
	tests.insert(Test(30, "Mike1"));
	tests.insert(Test(30, "Sue"));


	for(set<Test>:: iterator it = tests.begin(); it != tests.end(); it++){
		it->print();
	}

	cout << "Exited successfully!" << endl;


	return 0;
}
