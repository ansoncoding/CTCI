#include "pch.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class mystring {
private:
	char* m_data = nullptr;
	int m_size = 0;
	void cleanup() {
		if (m_data != nullptr) {
			delete[] m_data;
			m_data = nullptr;
		}
		m_size = 0;
	}

	void copy(const mystring& other) {
		int len = other.getSize();
		m_data = new char[len+1];
		memset(m_data, 0, len + 1);
		memcpy(m_data, other.m_data, len);
		m_size = len;
		cout << "***** DEEP COPY *****" << endl;
	}
	
public:
	int getSize() const {
		return m_size;
	}
	//constructor
	mystring(const char * data) {
		int len = strlen(data);
		m_data = new char[len+1];
		m_size = len;
		memset(m_data, 0, len + 1);
		memcpy(m_data, data, len);
		cout << "created" << endl;
	}
	//destructor
	~mystring() {
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
		cout << "destroyed" << endl;
	}
	// copy constructor
	mystring(const mystring& other) {
		copy(other);
		cout << "copy create" << endl;
	}

	//assignment operator
	mystring& operator=(const mystring& other) {
		if (&other != this) {
			cleanup();
			copy(other);
		}
		cout << "assign op" << endl;
		return *this;
	}

	// move constructor
	mystring(mystring&& other) noexcept {
		cleanup();
		m_size = other.m_size;
		m_data = other.m_data;
		other.m_data = nullptr;
		other.m_size = 0;
		cout << "moved op" << endl;
	}
	// move assignment operator
	mystring& operator=(mystring&& other) noexcept {
		this->m_size = other.m_size;
		this->m_data = other.m_data;

		other.m_data = nullptr;
		other.m_size = 0;
		cout << "assigned and moved op" << endl;
		return *this;
	}
	void print() {
		if (m_data) {
			cout << m_data << endl;
		}
		else {
			cout << "String is empty " << endl;
		}
	}
};

#if 0
int main() {

	// create
	{
		mystring s = mystring("Jane");
		s.print();
	}

	// copy 
	{
		mystring s = mystring("Jane");
		s.print();
		mystring a(s);
		a.print();
	}

	// copy and assign
	{
		mystring s = mystring("Jane");
		s.print();

		// if we simply do mystring a = s; because it's an initialization the compiler will optimize and call copy constructor instead.
		// so we'll first make a string called "Alice" and then assign it to invoke the assignment operator
		mystring a = mystring("Alice"); 
		a = s;
		a.print();
	}

	// move
	{
		mystring s = mystring("Jane");
		s.print();

		mystring a(move(s));
		a.print();
	}

	// move assignment
	{
		mystring s = mystring("Jane");
		s.print();

		mystring a = mystring("Alice");
		a = move(s);
		a.print();
	}
	
	system("pause");
	return 0;
}

#endif