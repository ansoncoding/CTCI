#include "pch.h"
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <chrono>
#include "Source.h"

using namespace std;
#if 0
int main()
{
    
    /*int* arr = new int[128];
    for (int i = 0; i < 128; i++) {
        arr[i] = i;
    }
    cout << *arr << endl;
    cout << *++arr << endl;
    cout << (*arr)++ << endl;*/
    extern int a;
    a = 1;
    cout << a << endl;
    
    system("pause");
    return 0;
}
#endif