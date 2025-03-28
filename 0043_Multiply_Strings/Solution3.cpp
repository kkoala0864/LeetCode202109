#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

string Solution::multiply3(string num1, string num2) {
	int size1 = num1.size();
	int size2 = num2.size();
	string result(size1 + size2, '0');

	for (int i = size1 - 1; i >= 0; --i) {
		int carry = 0;
		int idx = size1 - 1 - i;
		for (int j = size2 - 1; j >= 0; --j) {
			int val = (num1[i] - '0') * (num2[j] - '0') + carry + (result[idx] - '0');
			carry = val / 10;
			result[idx++] = val % 10 + '0';
		}
		while (carry > 0) {
			int val = result[idx] - '0' + carry;
			carry = val / 10;
			result[idx++] = val % 10 + '0';
		}
	}
	while (result.back() == '0')
		result.pop_back();
	reverse(result.begin(), result.end());
	return result.empty() ? "0" : result;
}
