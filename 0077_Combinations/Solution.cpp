#include <Solution.h>
#include <iostream>

void combineRecur(int n, int start, int k, vector<vector<int>> &result, vector<int> &local) {
	if (k == 1) {
		for (int i = start; i <= n; ++i) {
			local.emplace_back(i);
			result.emplace_back(local);
			local.pop_back();
		}
	} else {
		for (int i = start; i <= (n - k + 1); ++i) {
			local.emplace_back(i);
			combineRecur(n, i + 1, k - 1, result, local);
			local.pop_back();
		}
	}
}

vector<vector<int>> Solution::combine(int n, int k) {
	vector<vector<int>> result;
	vector<int> local;
	combineRecur(n, 1, k, result, local);
	return result;
}
