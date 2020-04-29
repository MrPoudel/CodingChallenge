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

//	unique_ptr<int> pInt(new int);
//	*pInt = 7;
//	cout << *pInt << endl;

	{
		unique_ptr<Test> pTest(new Test); // auto_ptr before C++11 but depricated now.
		pTest->greet();
	}

//
//	{
//		unique_ptr<Test[]> pTest1(new Test[2]);
//		pTest1[1].greet();
//	}

	{
		Temp temp;
	}


	cout << "Finished" << endl;

	return 0;
}

