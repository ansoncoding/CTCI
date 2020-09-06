#include "pch.h"
#include <iostream>

using namespace std;
#if 0
int main()
{
    int m = 0;
    int n = 0;
    [&, n](int a) mutable { m = ++n + a; }(4);
    cout << m << endl << n << endl;
    system("pause");
}
#endif