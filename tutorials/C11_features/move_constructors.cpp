#include <iostream>
#include <vector>
#include <memory.h> // Needed for memset

using namespace std;

class Test {
private:
	static const int SIZE=100;

	int *_pBuffer{nullptr};
public:
	Test(){
		cout << "Constructor" << endl;
		_pBuffer = new int[SIZE]{};
		//_pBuffer = new int[SIZE]();
		//memset(_pBuffer, 0, sizeof(int)*SIZE); //Can be avoided by () or {}
	}

	Test(int i) {
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
		// Alternatively we could also call the copy constructor.
		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));

		return *this;
	}

	// This is move constructor. Mutable rvalue
	// Advantage of move constructor: Unlike copy constructor we don't need to allocate memory.
	// We will steal the already allocated memory and assign the old memory as nullptr.
	// Deleting an object with value of nullpointer is safe.

	Test(Test &&other){
		cout << "Move constructor" << endl;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;
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


int main() {

	vector<Test> vec;
	vec.push_back(Test());


	return 0;
}
