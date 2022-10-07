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

int to_int(int rev_binary[32], int digits) {
	int retval = 0;
	for (int i = 0; i < digits; i++) {
		if (rev_binary[i] == 1) {
			retval += pow(2, i);
		}
	}
	return retval;
}

int to_rev_binary(int A, int binary[32]) {
	int digits = 0;
	for (int i = 0; i < 32; i++) {
		if (A % 2) {
			binary[i] = 1;
		}
		else {
			binary[i] = 0;
		}
		A >>= 1;
		digits++;
		if (A == 0) {
			break;
		}
	}
	return digits;
}

// CTCI 5.4
// return the next smaller integer that has same number of binary ones as the given integer N.
// E.g. 5 = 101 the next smallest integer which has 3 binary 1s is 011 which is 3
// E.g. 10 = 1010 the next smallest integer which as 2 binary 1s is 1001 which is 9
// If the integer has all ones E.g. 7 -> 111 (it's already the smallest number with the same number of integers,
// we will simply return the integer itself
int next_smallest(int N) {
	int binary[32] = { 0 };
	int digits = to_rev_binary(N, binary);
	bool found = false;

	// find "0, 1" combination and swap them
	for (int i = 0; i < digits - 1; i++) {
		if (binary[i] == 0 && binary[i + 1] == 1) {
			binary[i + 1] = 0;
			binary[i] = 1;
			found = true;
			break;
		}
	}
	if (found) {
		return to_int(binary, digits);
	}
	return N;
}

// CTCI 5.6
int conversion(int A, int B) {
	int digitsA = 0;
	int digitsB = 0;
	int A_binary[32] = { 0 };
	int B_binary[32] = { 0 };
	int diff = 0;
	digitsA = to_rev_binary(A, A_binary);
	digitsB = to_rev_binary(B, B_binary);
	int max_digits = digitsA > digitsB ? digitsA : digitsB;
	for (int i = 0; i < max_digits; i++) {
		if (A_binary[i] != B_binary[i]) {
			diff++;
		}
	}
	return diff;
}

int conversion2(int A, int B) {
	int xor = A ^ B;
	int diff = 0;
	while (xor != 0) {
		if (xor & 1) {
			diff++;
		}
		xor >>= 1;
	}
	return diff;
}

// CTCI 5.7
int swap_odd_even_bits(int N) {
	int retval = 0;
	unsigned int even = 0;
	unsigned int odd = 0;
	unsigned int odd_mask = 0xaaaaaaaa;
	unsigned int even_mask = 0x55555555;

	even = N & even_mask;
	odd = N & odd_mask;

	even <<= 1;
	odd >>= 1;

	retval = even | odd;
	return retval;
}

