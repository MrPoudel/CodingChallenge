#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int cats = 5;
	[cats]() mutable { // mutable does pass the cats by value but allows it to be changed locally inside lambda but will
		//contain the original value outside the scope of the lambda.
		cats = 8;
		cout << cats << endl;
	}();

    cout << cats << endl;
	cout << "Exited successfully!" << endl;

	return 0;
}
