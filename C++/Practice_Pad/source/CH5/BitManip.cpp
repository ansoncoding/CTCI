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

// CTCI 5.2
void print_decimal(double d) {
	if (d > 1 || d < 0) {
		throw invalid_argument("Only values between 0 and 1 are allowed");
	}
	cout << ".";
	for (int i = 1; i < 32; i++) {
		if (d >= (pow(0.5, i))) {
			cout << "1";
			d -= pow(0.5, i);
		}
		else {
			cout << "0";
		}
		if (d == 0) {
			break;
		}
	}
	cout << endl;
}

int main() {
	
	print_decimal(0.5);
	print_decimal(0.25);
	print_decimal(0.125);
	print_decimal(0.783);
	print_decimal(0.1);
	print_decimal(0.99);
	
}