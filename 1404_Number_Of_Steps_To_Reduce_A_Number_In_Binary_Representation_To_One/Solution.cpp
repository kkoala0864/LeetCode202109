#include <Solution.h>
#include <iostream>

int Solution::numSteps(string s) {
	int carry = 0;
	int result = 0;

	while (s.size() > 1) {
		int v = ((s.back() - '0') + carry) % 2;
		carry = ((s.back() - '0') + carry) / 2;
		s.pop_back();

		// v == 1 -> bit = 0, carry = 1 -> after add carry clear to 0 -> carry = 0 -> bit = 1, carry = 0
		// v == 1 -> bit = 1, carry = 0 -> after add carry not increase -> carry = 0 -> bit = 1, carry = 0
		if (v == 1) {
			++result;
			carry = 1;
		}
		++result;
	}
	return carry == 0 ? result : result + 1;
}
