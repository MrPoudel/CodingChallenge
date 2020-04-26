#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
	int id;
	string name;

public:
	Test(int id, string name): id(id), name(name){

	}

	~Test(){
		// cout << "Object destroyed" << endl;
	}

	void print(){
		cout << id << ":" << name << endl;
	}

//	bool operator< (const Test &other){
//		return id < other.id;
//	}

	friend bool cmp (const Test& a, const Test& b);
};


bool cmp (const Test &a, const Test &b){
	return a.name < b.name;
	//return a.id < b.id;
}

int main() {

	vector<Test> tests;

	tests.push_back(Test(5, "Mike"));
	tests.push_back(Test(10,"John"));
	tests.push_back(Test(7, "Sue"));
	tests.push_back(Test(17, "Hoi"));
	tests.push_back(Test(5, "Mike"));

	cout << endl;

//	sort(tests.begin(), tests.end());

	sort(tests.begin(), tests.end(), cmp);

	for(int i=0; i<tests.size(); i++)
	{
		tests[i].print();
	}

	cout << "Exited successfully!" << endl;


	return 0;
}
