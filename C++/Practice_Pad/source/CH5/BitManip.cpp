#include "pch.h"
#include "BitManip.h"

#include <string>

using namespace std;

void print_binary32(int x) {
	string s;
	if (x == 0) {
		cout << "0" << endl;
	}
	else if (x > 0) {
		while (x != 0) {
			char digit = (x & 1) ? '1' : '0';
			s.insert(s.begin(), digit);
			x >>= 1;
		}
	}
	else {
		int count = 0;
		while (x != -1) {
			char digit = (x & 1) ? '1' : '0';
			s.insert(s.begin(), digit);
			x >>= 1;
			count++;
		}
		int diff = 32 - count;
		for (int i = 0; i < diff; i++) {
			s.insert(s.begin(), '1');
		}
	}
	cout << s << endl;
}

// CTCI 5.1
// insert M into N starts at bit j, ends at bit i
// assume bits j - i have enough space to fit all of M.
int insert_binary(int N, int M, int posn_j, int posn_i) {
	for (int i = posn_j; i < posn_i+1; i++) {
		if (M % 2) {
			N |= (1 << i);
		}
		else {
			int mask = ~(1 << i);
			N &= mask;
		}
		cout << "M " << M << endl;
		M >>= 1;
		print_binary32(N);
	}
	return N;
}

int main() {
	int retval = insert_binary(1024, 19, 2, 6);
	
	print_binary32(retval);
}