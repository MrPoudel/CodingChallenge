#include <iostream>

using namespace std;

int main() {

	int values[] = {1, 4, 5};


	cout << values[0] << endl;

	class C {
	public:
		string text;
		int id;
	};

	C c1 = {"Hello from C", 7};

	cout << c1.text << endl;

	struct S {
		string text;
		int id;
	};

	S s1 = {"Hello from S", 7};
	cout << s1.text << endl;

	struct R {
			string text;
			int id;
		}r1 = {"Hello from R1", 7}, r2 = {"Hello from R2", 7};

	cout << r1.text << endl;
	cout << r2.text << endl;

	cout << "Exited successfully!" << endl;

	return 0;
}
