#include <iostream>
#include "ring.h"

using namespace std;

// Advance example in C++14 is here: https://codereview.stackexchange.com/questions/208293/ring-buffer-implementation-in-c14
int main() {

	ring<string> textstring(3);
	textstring.add("one");
	textstring.add("two");
	textstring.add("three");
//	textstring.add("four");

	for(int i=0; i<textstring.size(); i++){
		cout << textstring.get(i)<< endl;
	}

	cout << "Using user defined iterator.C++98 style" << endl;

	for(ring<string>::iterator it = textstring.begin(); it != textstring.end(); it++){
		cout << *it << endl;
	}

	cout << "Using C++11 syntax" << endl;
	for(auto text: textstring){
		cout << text << endl;
	}

//	/*
//	 * Output should be like this:
//	 * four
//	 * one
//	 * two
//	 */
//
//	ring<int>::iterator it;
//	it.print();


	cout << "Exited successfully!" << endl;

	return 0;
}
