#include <Solution.h>
#include <iostream>

string Solution::addBinary2(string a, string b) {
	if (a.size() != b.size()) {
		if (a.size() < b.size()) {
			a = string(b.size() - a.size(), '0') + a;
		} else {
			b = string(a.size() - b.size(), '0') + b;
		}
	}

	int carry = 0;
	for (int i = a.size() - 1 ; i >= 0 ; --i) {
		int sum = a[i] - '0' + b[i] - '0' + carry;
		a[i] = (sum % 2) + '0';
		carry = (sum) / 2;
	}
	return carry == 1 ? "1" + a : a;
}
