#include "pch.h"

#include<iostream> 
using namespace std;

class Person
{
    int age;
    string name;
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
        cout << "Person " << name << " " << age << endl;
    }
};

class Staff : public Person {
    int pay;
    int starting_year;
public:
    Staff(string name, int age, int pay, int starting_year) : Person(name, age) {
        this->pay = pay;
        this->starting_year = starting_year;
        cout << "Staff is paid " << pay << " per hour started in " << starting_year << endl;
    }
};

class TA : public Person , public Staff
{
    string class_name;
public:
    TA(string name, int age, string class_name) : Person(name, age), Staff(name, age, 14, 2020) {
        this->class_name = class_name;
        cout << "TA " << name << " teaches " << class_name << endl;
    }
};

int main()
{
    TA ta = TA("Alex", 19, "MATH 100");
    
    return 0;
}