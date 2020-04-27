#include <iostream>
#include <vector>

using namespace std;

int main() {

//	const char *texts[] = {"one", "two", "three"};
	auto texts = {"one", "two", "three"}; // This is exactly same as above.

	for(auto text: texts){
		cout << text << endl;
	}
	cout << endl;

	vector<int> numbers;
	numbers.push_back(7);
	numbers.push_back(9);
	numbers.push_back(11);

	for(auto number: numbers){
		cout << number << endl;
	}

	cout << endl;

	string hello = "Hello";
	for(auto c: hello){
		cout << c << endl;
	}

	cout << "Exited successfully!" << endl;

	return 0;
}
