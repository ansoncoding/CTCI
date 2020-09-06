#include "pch.h"
#include <iostream>

// decltype specifier

// TL;DR decltype is useful when declaring types that are difficult or impossible to declare using standard notation, 
// like lambda-related types or types that depend on template parameters.

// 1) decltype(entity)

// If the argument is an unparenthesized id-expression or an unparenthesized class member access expression, 
// then decltype yields the type of the entity named by this expression.
// If there is no such entity, or if the argument names a set of overloaded functions, the program is ill - formed.


// 2) decltype(expression) 
// If the argument is any other expression of type T, and
// a) if the value category of expression is xvalue, then decltype yields T&&;
// b) if the value category of expression is lvalue, then decltype yields T&;
// c) if the value category of expression is prvalue, then decltype yields T.

// If the expression e refers to a variable in local or namespace scope, a static member variable or a function parameter, 
// then the result is that variable's or parameter's declared type
// If e is a function call or an overloaded operator invocation, decltype(e) denotes the declared return type of that function
// Otherwise, if e is an lvalue, decltype(e) is T&, where T is the type of e; if e is an rvalue, the result is T


// If expression is a function call which returns a prvalue of class type or is a comma expression whose right operand is such a function call, 
// a temporary object is not introduced for that prvalue.

// decltype is useful when declaring types that are difficult or impossible to declare using standard notation, 
// like lambda-related types or types that depend on template parameters.


// ** Note that if the name of an object is parenthesized, it is treated as an ordinary lvalue expression, 
// thus decltype(x) and decltype((x)) are often different types.

using namespace std;


class M {
private:
	int m_data;
	
public:
	M(int data) {
		m_data = data;
	}
	void print() const {
		cout << m_data << endl;
	}
	friend M operator+(const M& a, const M& b) {
		return (a.m_data + b.m_data);
	}
};




struct A { 
	double x; 
};

const A* a;

decltype(a->x) y;       // type of y is double (declared type)
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) // return type depends on template parameters
									  // return type can be deduced since C++14
{
	return t + u;
}

int global{};
int& foo()
{
	return global;
}
#if 0
int main()
{
	int i = 33;
	decltype(i) j = i * 2;

	std::cout << "i = " << i << ", "
		<< "j = " << j << '\n';

	auto f = [](int a, int b) -> int
	{
		return a * b;
	};

	decltype(f) g = f; // the type of a lambda function is unique and unnamed
	// auto g = f; // this gives us the same result
	i = f(2, 2);
	j = g(3, 3);

	std::cout << "i = " << i << ", " << "j = " << j << '\n';


	// What is the difference between auto and decltype?
	// decltype gives the declared type of the expression that is passed to it. 
	// auto does the same thing as template type deduction.
	// E.g. you have a function that returns a reference, auto will still be a value(you need auto & to get a reference), 
	// but decltype will be exactly the type of the return value.

	decltype(foo()) a = foo(); //a is an int&
	auto b = foo(); //b is an int
	b = 2;

	std::cout << "a: " << a << '\n'; //prints "a: 0"
	std::cout << "b: " << b << '\n'; //prints "b: 2"

	std::cout << "---\n";
	decltype(foo()) c = foo(); //c is an int&
	c = 10;

	std::cout << "a: " << a << '\n'; //prints "a: 10"
	std::cout << "b: " << b << '\n'; //prints "b: 2"
	std::cout << "c: " << c << '\n'; //prints "c: 10"
	
	// auto (in the context where it infers a type) is limited to defining the type of a variable for which there is an initializer. 
	// decltype is a broader construct that, at the cost of extra information, will infer the type of an expression.

	// auto follows the rules of template parameter deduction.
	// -- In order to instantiate a function template, every template argument must be known, but not every template argument has to be specified
	// -- When possible, the compiler will deduce the missing template arguments from the function arguments. 
	// -- This occurs when a function call is attempted, when an address of a function template is taken

	// In the cases where auto can be used, it is more concise than decltype, as you don't need to provide the expression 
	// from which the type will be inferred.

	auto x = foo();                           // more concise than decltype(foo()) x
	std::vector<decltype(foo())> v{ foo() };  // cannot use auto
	
	system("Pause");
}
#endif

#if 0
int main() {
	{
		
		M v1 = M(2);
		M v2 = M(3);
		M out1 = v1 + v2;
		M out2 = add(v1, v2);
		cout << add(1.2, 2) << endl;
		out1.print();
		out2.print();
		
	}
}


#endif