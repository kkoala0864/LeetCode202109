#include <Solution.h>
#include <iostream>

void dfs(int idx, int n, int k, vector<int>& local, vector<vector<int>>& result) {
	if (k == 1) {
		for (int i = idx ; i <= n ; ++i) {
			local.emplace_back(i);
			result.emplace_back(local);
			local.pop_back();
		}
		return;
	}

	for (int i = idx ; i <= (n - k + 1) ; ++i) {
		local.emplace_back(i);
		dfs(i+1, n, k - 1, local, result);
		local.pop_back();
	}
}

vector<vector<int>> Solution::combine2(int n, int k) {
	vector<vector<int>> result;
	vector<int> local;
	dfs(1, n, k, local, result);
	return result;
}
