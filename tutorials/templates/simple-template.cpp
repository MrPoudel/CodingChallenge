
#include <iostream>

using namespace std;

template<class T>
class Test {
private:
	T obj;

public:
	Test(T obj){
		this->obj = obj;
		cout << "Constructor called!" << endl;
		cout << obj << endl;
	}

	void print() const{
		cout << obj << endl;
	}
};

int main() {

	Test<string> test1("Hello");
	test1.print();


	cout << "Exited successfully!" << endl;
	return 0;
}
