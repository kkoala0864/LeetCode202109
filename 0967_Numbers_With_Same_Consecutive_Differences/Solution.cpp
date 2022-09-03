#include <Solution.h>
#include <iostream>

void dfs(int n, int k, int idx, int val, int local, vector<int>& result) {
	if (n == idx) {
		result.emplace_back(local);
		return;
	}

	int next = local * 10;
	if (val - k >= 0) dfs(n, k, idx + 1, val - k, next + (val - k), result);
	if (k > 0) if (val + k <= 9) dfs(n, k, idx + 1, val + k, next + (val + k), result);
}

vector<int> Solution::numsSameConsecDiff(int n, int k) {
	vector<int> result;
	int local = 0;
	for (int i = 1 ; i <= 9 ; ++i) {
		local = i;
		dfs(n, k, 1, i, local, result);
	}
	return result;
}
