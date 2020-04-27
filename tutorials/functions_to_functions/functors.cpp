#include <iostream>

using namespace std;

struct Test{
	virtual bool operator()(string&text)=0;

	virtual ~Test(){}
};

// This is functor
struct MatchTest: public Test{
	bool operator()(string&text){
		return text == "lion";
	}
};

void check(string text, Test& test){
	if(test(text)){
		cout << "Text matches!" << endl;
	}
	else{
		cout << "No match." << endl;
	}
}

int main() {

	MatchTest pred;
	string value = "liond";

	cout << pred(value) << endl;

	MatchTest m;

	check(value, m);

	cout << "Exited successfully!" << endl;

	return 0;
}
