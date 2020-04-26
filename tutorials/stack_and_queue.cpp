#include <iostream>
#include<stack>
#include<queue>

using namespace std;

class Test {
	string name;

public:
	Test(string name): name(name){

	}

	~Test(){
		// cout << "Object destroyed" << endl;
	}

	void print(){
		cout << name << endl;
	}
};

int main() {

	// LIFO
	stack<Test> testStack;

	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Sue"));

	cout << endl;

	while(testStack.size() > 0)
	{
		Test &test1 = testStack.top();
		test1.print();

		testStack.pop();
	}


	// FIFO
	queue<Test> testQueue;

	testQueue.push(Test("Mike"));
	testQueue.push(Test("John"));
	testQueue.push(Test("Sue"));

	cout << endl;

	while(testQueue.size() > 0)
	{
		Test &test1 = testQueue.front();
		test1.print();

		testQueue.pop();
	}

	cout << "Exited successfully!" << endl;


	return 0;
}
