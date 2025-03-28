#include <Solution.h>
#include <iostream>

void DFS(int n, int idx, vector<int> &local, vector<vector<int>> &result) {
	if (n == 1) {
		if (local.size() > 1)
			result.emplace_back(local);
		return;
	}

	for (int i = idx; i * i <= n; ++i) {
		if (n % i != 0)
			continue;
		local.emplace_back(i);
		local.emplace_back(n / i);
		result.emplace_back(local);
		local.pop_back();
		DFS(n / i, i, local, result);
		local.pop_back();
	}
}

vector<vector<int>> Solution::getFactors2(int n) {
	vector<vector<int>> result;
	vector<int> local;
	DFS(n, 2, local, result);
	return result;
}
