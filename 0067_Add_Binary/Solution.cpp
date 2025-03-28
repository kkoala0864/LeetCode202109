#include <Solution.h>
#include <iostream>

string Solution::addBinary(string a, string b) {
	int carry = 0;
	string result("");
	while (!a.empty() && !b.empty()) {
		int first = a.back() - '0';
		a.pop_back();
		int second = b.back() - '0';
		b.pop_back();
		result = string(1, (first + second + carry) % 2 + '0') + result;
		carry = (first + second + carry) / 2;
	}
	// difference size
	string rest = a.empty() ? b : a;
	while (!rest.empty() && carry != 0) {
		int val = rest.back() - '0';
		rest.pop_back();
		result = string(1, (val + carry) % 2 + '0') + result;
		carry = (val + carry) / 2;
	}

	if (!rest.empty())
		result = rest + result;
	// carry in handle
	if (carry != 0)
		result = "1" + result;

	return result;
}
