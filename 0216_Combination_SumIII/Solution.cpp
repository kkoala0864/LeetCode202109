#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

void dfs(int idx, int k, int n, vector<int>& local, vector<vector<int>>& result) {
	if (k < 0 || n < 0) return;
	if (k == 0 && n == 0) {
		result.emplace_back(local);
		return;
	}

	for (int i = idx + 1 ; i <= 9 ; ++i) {
		local.emplace_back(i);
		dfs(i, k - 1, n - i, local, result);
		local.pop_back();
	}
}

vector<vector<int>> Solution::combinationSum3(int k, int n) {
	vector<vector<int>> result;
	vector<int> local;
	dfs(0, k, n, local, result);
	return result;
}
