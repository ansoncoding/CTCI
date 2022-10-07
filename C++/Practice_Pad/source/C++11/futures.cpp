#include "pch.h"
#include <future>
#include <iostream>


using namespace std;
#if 0
int timesTwo(int x) {
	return x * 2;
}


int main() {
	future<int> fu = async(timesTwo, 4);
	cout << fu.get() << endl;
}

#endif