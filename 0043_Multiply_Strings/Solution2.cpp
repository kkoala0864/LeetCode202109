#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

string Solution::multiply2(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";
	string result(num1.size() + num2.size(), '0');

	int m = num1.size();
	int n = num2.size();
	int carry = 0;
	for (int i1 = m - 1 ; i1 >= 0 ; --i1) {
		for (int i2 = n - 1 ; i2 >= 0 ; --i2) {
			int v1 = num1[i1] - '0';
			int v2 = num2[i2] - '0';

			int idx = m - 1 - i1 + n - 1 - i2;
			int val = v1 * v2 + carry + (result[idx] - '0');

			result[idx] = val % 10 + '0';
			carry = val / 10;
		}
		int idx = m - 1 - i1 + n;
		while (carry > 0) {
			int val = carry + (result[idx] - '0');
			result[idx] = val % 10 + '0';
			carry = val / 10;
			++idx;
		}
	}
	while (result.back() == '0') result.pop_back();
	reverse(result.begin(), result.end());
	return result;
}

