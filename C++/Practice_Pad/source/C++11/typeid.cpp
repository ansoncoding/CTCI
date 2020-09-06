#include "pch.h"
#include <typeinfo>
#include <iostream>
#include <string>

//Queries information of a type.

// Used where the dynamic type of a polymorphic object must be knownand for static type identification.

// The header <typeinfo> must be included before using typeid (if the header is not included, every use of the keyword typeid makes the 
// program ill-formed.)
// The typeid expression is an lvalue expression which refers to an object with static storage duration, of the polymorphic type 
// const std::type_info or of some type derived from it.

// 1) typeid(type)
//    Refers to a std::type_info object representing the type type.If type is a reference type, the result refers to a std::type_info object representing the referenced type.

// 2) typeid(expression)
//    Examines the expression 
// -- a) If expression is a glvalue expression that identifies an object of a polymorphic type
//       I.E. a class that declares or inherits at least one virtual function - the typeid expression evaluates the expression
//        and then refers to the std::type_info object that represents the dynamic type of the expression.
//       If the glvalue expression is obtained by applying the unary* operator to a pointer and the pointer is a null pointer value, 
//       an exception of type std::bad_typeid or a type derived from std::bad_typeid is thrown.
// -- b) If expression is not a glvalue expression of polymorphic type, typeid does not evaluate the expression, and the std::type_info object 
//       it identifies represents the static type of the expression. Lvalue-to-rvalue, array-to-pointer, or function-to-pointer conversions 
//       are not performed.

// In all cases, cv-qualifiers are ignored by typeid (that is, typeid(const T) == typeid(T))

// If the operand to typeid is a class type or a reference to a class type, then that class type must not be an incomplete type.

// If typeid is used on an object under construction or destruction(in a destructor or in a constructor, including constructor's initializer 
// list or default member initializers), then the std::type_info object referred to by this typeid represents the class that is being 
// constructed or destroyed even if it is not the most-derived class.


struct Base {}; // non-polymorphic
struct Derived : Base {};

struct Base2 { 
    virtual void foo() {} 
}; // polymorphic

struct Derived2 : Base2 {};

#if 0
int main() {
    int myint = 50;
    std::string mystr = "string";
    double* mydoubleptr = nullptr;


    std::cout << "myint has type: " << typeid(int).name() << '\n'
        << "mystr has type: " << typeid(std::string).name() << '\n'
        << "mydoubleptr has type: " << typeid(double*).name() << '\n';

    std::cout << "myint has type: " << typeid(myint).name() << '\n'
              << "mystr has type: " << typeid(mystr).name() << '\n'
              << "mydoubleptr has type: " << typeid(mydoubleptr).name() << '\n';

    
    // std::printf() is not a glvalue expression of polymorphic type; NOT evaluated
    const std::type_info& r2 = typeid(std::printf("%d\n", myint));
    std::cout << "printf(\"%d\\n\",myint) has type : " << r2.name() << '\n';

    // Non-polymorphic lvalue is a static type
    Derived d1;
    Base& b1 = d1;
    std::cout << "reference to non-polymorphic base: " << typeid(b1).name() << '\n';

    Derived2 d2;
    Base2& b2 = d2;
    std::cout << "reference to polymorphic base: " << typeid(b2).name() << '\n';

    try {
        // dereferencing a null pointer: okay for a non-polymorphic expression
        std::cout << "mydoubleptr points to " << typeid(*mydoubleptr).name() << '\n';
        // dereferencing a null pointer: not okay for a polymorphic lvalue
        Derived2* bad_ptr = nullptr;
        std::cout << "bad_ptr points to... ";
        std::cout << typeid(*bad_ptr).name() << '\n';
    }
    catch (const std::bad_typeid& e) {
        std::cout << " caught :" << e.what() << '\n';
    }

    system("pause");
}

#endif