// https://www.udemy.com/course/learn-advanced-c-programming/learn/lecture/3688266#questions
#include <iostream>
#include <map>

using namespace std;

class Person{
private:
	string name;
	int age;

public:
	Person():name(""), age(0){

	}

	Person(const Person &other){
		cout << "Copy constructor running!" << endl;
		name = other.name;
		age = other.age;
	}

	Person(string name, int age):
		name(name), age(age){
	}
	void print() const{
		cout << name << ":" << age << endl;
	}
};

int main() {

	map<int, Person> people;

	people[0] = Person("Mike", 40);
	people[97] = Person("Harry", 30);
	people[2] = Person("Barry", 20);

	people.insert(make_pair(55, Person("Bob", 45)));
	people.insert(make_pair(52, Person("Sue", 21)));



	for(map<int, Person >::iterator it = people.begin(); it != people.end(); it++){

//			pair<int, Person> person = *it;
//
//			cout << person.first << ":";
//			person.second.print();
//			cout << endl;

			cout << it->first << ":" << flush;
			it->second.print();
	}

	cout << "Exited successfully!" << endl;


	return 0;
}
