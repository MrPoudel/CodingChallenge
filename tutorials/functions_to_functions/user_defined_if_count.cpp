#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

bool match(string test){
	return test.size() == 3;
}

int countStrings(vector<string> &texts, bool (*check)(string test)){

   int count = 0;

   for(vector<string>::iterator it = texts.begin(); it != texts.end(); it++){
	   if(check(*it)){
		   count++;
	   }
   }

   return count;
}

int main() {

	vector<string> texts;
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("two");
	texts.push_back("four");
	texts.push_back("two");
	texts.push_back("three");

	cout << count_if(texts.begin(), texts.end(), match) << endl;
	cout << "From use defined funcion:" << countStrings(texts, &match) << endl;

	cout << "Exited successfully!" << endl;
	return 0;
}

