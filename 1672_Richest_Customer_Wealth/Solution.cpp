#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maximumWealth(vector<vector<int>>& accounts) {
	int result = 0;
	for (const auto& account : accounts) {
		int local = 0;
		for (const auto& iter : account) {
			local += iter;
		}
		result = max(result, local);
	}
	return result;
}
