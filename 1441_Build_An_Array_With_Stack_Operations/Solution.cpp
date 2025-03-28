#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

vector<string> Solution::buildArray(vector<int> &target, int n) {
	vector<string> result;

	int base = target.back();

	int iter = target.size() - 1;
	while (iter >= 0) {
		if (target[iter] == base) {
			result.emplace_back("Push");
			--iter;
		} else {
			result.emplace_back("Pop");
			result.emplace_back("Push");
		}
		--base;
	}
	while (base >= 1) {
		result.emplace_back("Pop");
		result.emplace_back("Push");
		--base;
	}
	reverse(result.begin(), result.end());
	return result;
}
