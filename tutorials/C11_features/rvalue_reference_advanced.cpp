#include <iostream>
#include <vector>
#include <memory.h> // Needed for memset

using namespace std;

class Test {
private:
	static const int SIZE=100;

	int *_pBuffer;
public:
	Test(){
		cout << "Constructor" << endl;
		_pBuffer = new int[SIZE]{};
		//_pBuffer = new int[SIZE]();
		//memset(_pBuffer, 0, sizeof(int)*SIZE); //Can be avoided by () or {}
	}

	Test(int i) {
		cout << "parameterized constructor" << endl;
		_pBuffer = new int[SIZE]{};

		for(int i = 0; i<SIZE; i++){
			_pBuffer[i] = 7*i;
		}
	}

	Test(const Test &other) {
		cout << "Copy constructor" << endl;
		_pBuffer = new int[SIZE]{};
	}

	Test &operator=(const Test &other){
		cout << "assignment" << endl;
		// Alternatively we could also call the copy constructor.
		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));

		return *this;
	}

	~Test(){
		cout << "destructor" << endl;

		delete [] _pBuffer;
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

void check(Test &value){
	cout << "lValue function!" << endl;
}

void check(Test &&value){
	cout << "rValue function!" << endl;
}


int main() {

	Test test1 = getTest();
	cout << test1 << endl;

	// Test for vectors

	cout << "Regarding vectors:" << endl;

	vector<Test> vec;
	vec.push_back(Test());

	Test &ltest1 = test1;
	Test &&rtest1 = getTest();

	check(test1);
	check(getTest());
	check(Test());

	cout << "Exited successfully!" << endl;

	return 0;
}

