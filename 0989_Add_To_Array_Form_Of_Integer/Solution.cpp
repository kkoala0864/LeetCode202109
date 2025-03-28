#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

vector<int> Solution::addToArrayForm(vector<int> &num, int k) {
	vector<int> result;
	int carry = 0;
	for (int i = num.size() - 1; i >= 0 || k > 0; --i, k /= 10) {
		if (i >= 0)
			carry += num[i];
		if (k > 0)
			carry += (k % 10);
		result.emplace_back(carry % 10);
		carry /= 10;
	}
	if (carry > 0)
		result.emplace_back(carry);
	reverse(result.begin(), result.end());
	return result;
}
