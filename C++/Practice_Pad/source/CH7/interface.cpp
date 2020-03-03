#include "pch.h"
#include <string>

using namespace std;

class Printable {
	
public : 
	virtual void print() = 0;
};

class Person : public Printable {
private: 
	string name;
	unsigned int age;
public:
	Person(string name, unsigned int age) {
		this->name = name;
		this->age = age;
	}

	void print() {

		cout << name << " " << age << endl;
	}
};

int main() {
	string carl = "Carl";
	Person p = Person(carl, 52);
	p.print();
}