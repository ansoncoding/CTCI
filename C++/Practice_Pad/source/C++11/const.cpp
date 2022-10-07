#include "pch.h"
#include <vector>

// When modifying a data declaration, the const keyword specifies that the object or variable is not modifiable.

// 3 ways to use const keyword

// 1) const declaration ; E.g. const int x =10;
// 2) function signature return value
// 3) function parameter passing
// 4) function method. E.g. void function() const {...};


char* Function1()
{
    return "Some text";
}

const char* Function1Fixed()
{
    return "Some text";
}

void Subroutine1(int Parameter1)
{
    printf("%d", Parameter1);
}

void Subroutine4(const std::vector<int>& Parameter1) {
}

#if 0
int main() {

    // ======================================================
    //                     CONST DECLARATIONS
    // ======================================================
    // const int j; // not allowed, these values have to be initialized
    const int i = 5;
    // i = 10;   // C3892 not allowed
    // i++;   // C2105 not allowed

    // In C++, you can use the const keyword instead of the #define preprocessor directive to define constant values.
    // Values defined with const are subject to type checking, and can be used in place of constant expressions.
    // In C++, you can specify the size of an array with a const variable as follows :

    const int maxarray = 255;
    char store_char[maxarray];  // allowed in C++; not allowed in C


    // In C, constant values default to external linkage, so they can appear only in source files.
    // In C++, constant values default to internal linkage, which allows them to appear in header files.
    // The const keyword can also be used in pointer declarations.

    // but one has to be careful where ‘const’ is put as that determines whether the pointer or what it points to is constant.
    //For example,
    
    const int* p1a; // declares that p1a is a variable pointer to a constant integer
    int const* p1b; // declares that p1b is a variable pointer to a constant integer, rarely used

    int a;
    int b;
    int* const p3 = &a; // declares that p3 is constant pointer to a variable integer
    int const* const p4 = &b;// declares that p4 is constant pointer to a constant integer
    //const applies to whatever is on its immediate left(other than if there is nothing there in which case it applies to whatever is its immediate right).

    p1a = &a; // OK because we're changing the pointer
    //*p1a = 2; // not OK because we're changing the value

    p1b = &b; // ok because we're changing the pointer 
    //*p1b = 3; // not OK because we're changing the value

    //p3 = &b; // not OK because we're changing the pointer
    *p3 = 3; // OK because we're changing the value

    // p4 = &a; // not OK because we're changintg the pointer
    // *p4 = 4; // not OK because we're changing the value


    // ======================================================
    //                 CONST FUNCTION RETURNS
    // ======================================================
    
    // compare Function1 and Function1Fixed, the first one will crash if this were to execute:
    //Function1()[1] = 'a'; // crash during run time, write access violation
    //Function1Fixed()[1] = 'a'; // won't compile


    // ======================================================
    //                 CONST FUNCTION PARAMETERS
    // ======================================================

    // When a subroutine or function is called with parameters, variables passed as the parameters might be read from in order 
    // to transfer data into the subroutine / function, written to in order to transfer data back to the calling program or 
    // both to do both. Some languages enable one to specify this directly, such as having 'in : ', 'out : ' & 'inout : '
    // parameter types, whereas in C one has to work at a lower level and specify the method for passing the variables 
    // choosing one that also allows the desired data transfer direction.

    // For example, a subroutine like Subroutine1 accepts the parameter passed to it in the default C/C++ way - which is a copy.
    // Therefore the subroutine can read the value of the variable passed to it but not alter it because any alterations 
    // it makes are only made to the copy and are lost when the subroutine ends.

    // In Subroutine4 we use const to ensure that the passed reference won't be modified

    // ======================================================
    //                 CONST OBJECT METHODS
    // ======================================================

    // adding const to read-only methods E.g. void getSize() const { return m_size};

    system("pause");
}
#endif