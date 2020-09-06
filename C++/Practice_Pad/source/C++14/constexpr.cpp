#include "pch.h"

// The keyword constexpr was introduced in C++11 and improved in C++14. 
// It means constant expression. 
// Like const, it can be applied to variables: A compiler error is raised when any code attempts to modify the value. 
// Unlike const, constexpr can also be applied to functions and class constructors. 
// constexpr indicates that the value, or return value, is constant and, where possible, is computed at compile time.

// A constexpr integral value can be used wherever a const integer is required, such as in template arguments and array declarations.
// And when a value is computed at compile time instead of run time, it helps your program run faster and use less memory.

// To limit the complexity of compile-time constant computations, and their potential impacts on compilation time, 
// the C++14 standard requires the types in constant expressions to be literal types.

// 4 ways of using constexpr
//constexpr literal-type identifier = constant-expression ;
// constexpr literal-type identifier { constant - expression };
// constexpr literal-type identifier(params);
// constexpr constructor(params);

// The primary difference between constand constexpr variables is that the initialization of a const variable can be deferred 
// until run time. A constexpr variable must be initialized at compile time. All constexpr variables are const.

// A variable can be declared with constexpr, when it has a literal type and is initialized.
// If the initialization is performed by a constructor, the constructor must be declared as constexpr.

// A reference may be declared as constexpr when both these conditions are met : 
//   1) The referenced object is initialized by a constant expression
//   2) Any implicit conversions invoked during initialization are also constant expressions.

// All declarations of a constexpr variable or function must have the constexpr specifier.

constexpr float exp1(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp1(x * x, n / 2) :
        exp1(x * x, (n - 1) / 2) * x;
};

#if 0
int main() {

    // CONSTEXPR VARIABLES

    constexpr float x = 42.0;
    constexpr float y{ 108 };
    constexpr float z = exp1(5, 3);
    // constexpr int i; // Error! Not initialized. All constexpr must be initialized at declaration
    int j = 0;
    //constexpr int k = j + 1; //Error! j not a constant expression

    system("pause");
    return 0;
}

#endif

// CONSTEXPR FUNCTIONS


// A constexpr function is one whose return value is computable at compile time when consuming code requires it.
// Consuming code requires the return value at compile time to initialize a constexpr variable, or to provide a non-type template 
// argument. 
// When its arguments are constexpr values, a constexpr function produces a compile-time constant.
// When called with non-constexpr arguments, or when its value isn't required at compile time, it produces a value at run time 
// like a regular function. (This dual behavior saves you from having to write constexpr and non-constexpr versions of the same function.)
// A constexpr function or constructor is implicitly inline.

// The following rules apply to constexpr functions:

// -- A constexpr function must accept and return only literal types.
// -- A constexpr function can be recursive.
// -- It can't be virtual. 
// -- A constructor can't be defined as constexpr when the enclosing class has any virtual base classes.
// -- The body can be defined as = default or = delete.
// -- The body canNOT contain goto statements or try blocks.
// -- An explicit specialization of a non-constexpr template can be declared as constexpr:
// -- An explicit specialization of a constexpr template doesn't also have to be constexpr:

// The following rules apply to constexpr functions in Visual Studio 2017 and later :
// -- It may contain if and switch statements, and all looping statements including for, range - based for, while, and do - while.
// -- It may contain local variable declarations, but the variable must be initialized.
//    It must be a literal type, and can't be static or thread-local. 
//    The locally declared variable isn't required to be const, and may mutate.
// -- A constexpr non-static member function isn't required to be implicitly const.

// **** TIP ***** 
// In the VS debugger, when debugging a non-optimised Debug build, you can tell whether a constexpr function is being evaluated 
// at compile time by putting a breakpoint inside it. If the breakpoint is hit, the function was called at run-time.
// If not, then the function was called at compile time.

// The following example shows constexpr variables, functions, and a user-defined type.
// In the last statement in main(), the constexpr member function GetValue() is a run-time call because the value isn't required 
// to be known at compile time.


#include <iostream>

using namespace std;

// Pass by value
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};

// Pass by reference
constexpr float exp2(const float& x, const int& n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp2(x * x, n / 2) :
        exp2(x * x, (n - 1) / 2) * x;
};

// Compile-time computation of array length
template<typename T, int N>
constexpr int length(const T(&)[N])
{
    return N;
}

// Recursive constexpr function
constexpr int fac(int n)
{
    return n == 1 ? 1 : n * fac(n - 1);
}

// User-defined type
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue() const
    {
        return _i;
    }
private:
    int _i;
};
#if 0
int main()
{
    // foo is const:
    constexpr Foo foo(5);
    // foo = Foo(6); //Error!

    // Compile time:
    constexpr float x = exp(5, 3);
    constexpr float y{ exp(2, 5) };

    constexpr int val = foo.GetValue();
    constexpr int f5 = fac(5);
    const int nums[]{ 1, 2, 3, 4 };
    const int nums2[length(nums) * 2]{ 1, 2, 3, 4, 5, 6, 7, 8 };

    // Run time:
    // The constexpr member function GetValue() is a run-time call because the value isn't required 
    // to be known at compile time.
    cout << "The value of foo is " << foo.GetValue() << endl;
}
#endif