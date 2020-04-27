
#include <iostream>

using namespace std;

template<typename T>
void print(T n){
	cout << n << endl;
}

int main() {

	print<string>("Hello");
	print<int>(7);

	print("Hi there"); // C++ loads the arguments and infers what type of argument it is!


	cout << "Exited successfully!" << endl;
	return 0;
}
