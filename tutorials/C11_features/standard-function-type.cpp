#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string &text){
	return text.length() == 3;
}

class Check{
public:
	bool operator()(string &test){
		return test.size() == 7;
	}
}check1;

// using function
void run(function<bool(string&)> check) {
	string test = "stars";

	cout << "Inside function:" << endl;
	cout << check(test) << endl;
}


int main() {

	int size = 5;

	vector<string> vec{"one", "two", "three", "seven12"};

	auto lambda = [size](string test){ return test.size() == size; };

	int count = count_if(vec.begin(), vec.end(), lambda); //count_if --> from algorithm
    cout << count << endl;

    // Instead of passing the lambda function, let's pass a function pointer here.
    count = count_if(vec.begin(), vec.end(), &check);
    cout << count << endl;

    //Check check1;
    count = count_if(vec.begin(), vec.end(), check1);
    cout << count << endl;


    run(lambda);
    run(check1);
    run(check);

    function<int(int, int)> add = [](int one, int two){ return one+two;};
    cout << add(7, 3) << endl;

    auto add2 = [](int one, int two){ return one+two;};
    cout << add2(7, 3) << endl;

	cout << "Exited successfully!" << endl;

	return 0;
}
