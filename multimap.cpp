//============================================================================
// Name        : Vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

using namespace std;

int main() {

	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vickey"));
	lookup.insert(make_pair(20, "Bob"));
	lookup.insert(make_pair(20, "Bob"));
	lookup.insert(make_pair(20, "Bob"));


	for(multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++){

			cout << it->first << ":" << it->second << endl;
	}

	cout << endl;

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

	for(multimap<int, string>::iterator it = its.first; it != its.second; it++){

				cout << it->first << ":" << it->second << endl;
	}

	cout << endl;

	auto its2 = lookup.equal_range(30); //its;

	for(multimap<int, string>::iterator it = its2.first; it != its2.second; it++){

				cout << it->first << ":" << it->second << endl;
	}

	cout << "Exited successfully!" << endl;


	return 0;
}
