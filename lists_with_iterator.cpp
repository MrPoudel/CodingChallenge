// Udemy Advanced C++ class.

#include <iostream>
#include <list>

using namespace std;

int main() {

	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(-7); // -7, 1, 2, 3


	list<int>::iterator it = numbers.begin();
	it++;
	it = numbers.insert(it, 100); // -7, 100, 1, 2, 3
	cout<< "Element:" << "Inserted:" << *it << endl; // 100

	list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	eraseIt = numbers.erase(eraseIt); // -7, 1, 2, 3
	cout << "Now, value at erased location is:" << *eraseIt << endl; // 1

	it = numbers.begin();

	while(it != numbers.end()) {
			if(*it == 2){
				numbers.insert(it, 555); // -7, 555, 2, 3
				cout << "Inserted:" << *it << endl; //may be it prints 2... I don't know at this point!
			}

			if(*it == 1){
				it = numbers.erase(it);
				cout << "after it points to:" << *it << endl; //2   --> -7, 2, 3
			}
			else{
				it++;
			}
		}

	for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it ++){
		cout<< *it << endl;         // -7, 555, 2, 3
	}

	cout << "Exited successfully!" << endl;


	return 0;
}
