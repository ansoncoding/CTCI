#include "pch.h"
#include "BitManip.h"

#include <string>

using namespace std;

string get_binary32(int x) {
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
	return s;
}


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

// CTCI 5.3
// you can flip 1 bit, what is the longest of the length of the sequence of 1s possible from given input?
int flip_to_win(int N) {
	string s = get_binary32(N);
	cout << s << endl;
	int longest_ones_sequence_length = 0;
	if (s.empty()) {
		return 1;
	}
	int count = 0;
	int count2 = 0;
	bool oddZero = false;
	bool flipped = false;
	bool flipped2 = false;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '1') {
			count++;
			count2++;
			if (count > longest_ones_sequence_length) {
				longest_ones_sequence_length = count;
			}
			if (count2 > longest_ones_sequence_length) {
				longest_ones_sequence_length = count2;
			}
		}
		else {
			oddZero = !oddZero;

			if (oddZero) {
				
				if (count > 0 && !flipped) {
					flipped = true;
					count++;
					if (count > longest_ones_sequence_length) {
						longest_ones_sequence_length = count;
					}
				}
				else if (flipped) {
					flipped = false;
					count = 0;
				}
				count2 = 0;
				flipped2 = false;
			}
			else {
				if (count2 > 0 && !flipped2) {
					flipped2 = true;
					count2++;
					if (count2 > longest_ones_sequence_length) {
						longest_ones_sequence_length = count2;
					}
				}
				else if (flipped2) {
					flipped2 = false;
					count2 = 0;
				}
				count = 0;
				flipped = false;
			}
			
		}
	}
	if (longest_ones_sequence_length == 0) {
		return 1;
	}
	return longest_ones_sequence_length;
}

int main() {
	int retval = flip_to_win(1775);
	cout << " soln = " << retval << endl;

	retval = flip_to_win(11);
	cout << " soln = " << retval << endl;

	retval = flip_to_win(12345);
	cout << " soln = " << retval << endl;
	
	retval = flip_to_win(128);
	cout << " soln = " << retval << endl;

	retval = flip_to_win(255);
	cout << " soln = " << retval << endl;

	retval = flip_to_win(4247);
	cout << " soln = " << retval << endl;
	
}