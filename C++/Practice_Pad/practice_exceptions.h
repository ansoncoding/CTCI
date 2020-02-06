#ifndef PRACTICE_EXCEPTIONS_H
#define PRACTICE_EXCEPTIONS_H

#include <exception>

using namespace std;

class OutofBoundsException : public exception {
public:
    const char* what() const throw () {
        return "Index is out of bounds";
    }
};

#endif
