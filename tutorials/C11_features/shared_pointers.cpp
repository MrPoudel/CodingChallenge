#include <iostream>
#include <memory> // needed for the smart pointers.

using namespace std;


class Test{
public:
	Test(){
		cout << "created" << endl;
	}

	void greet(){
		cout << "Hello" << endl;
	}

	~Test(){
		cout << "destroyed" << endl;
	}
};

class Temp{
private:
	unique_ptr<Test[]> pTest1;

public:
	Temp(): pTest1(new Test[2]){

	}

};

int main() {

	shared_ptr<Test> pTest2(nullptr);

	{
		shared_ptr<Test> pTest1 = make_shared<Test>();
		pTest2 = pTest1;
	}

	cout << "Finished" << endl;

	return 0;
}

