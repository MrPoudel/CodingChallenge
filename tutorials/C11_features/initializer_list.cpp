#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Test{
public:
	Test(initializer_list<string> texts){ // this is iterable ...
		for(auto value: texts){
			cout << value << endl;
		}
	}

	void print(initializer_list<string> texts){
		for(auto value: texts){
			cout << value << endl;
		}
	}
};

int main() {

	vector<int> numbers {1, 2, 3, 4};
	cout << numbers[2] << endl;

	Test test{"apple", "orange", "banana"};

	cout << "With initilaizer_list:" << endl;
	test.print({"one", "two", "three", "four"});

	cout << "Exited successfully!" << endl;

	return 0;
}
