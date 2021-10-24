#include <Solution.h>
#include <iostream>
#include <math.h>

void dfs(int target, int idx, vector<int>& local, vector<vector<int>>& result) {
	if (target == 1) {
		if (local.size() > 1) result.emplace_back(local);
		return;
	}

	for (int i = idx ; i * i <= target ; ++i) {
		if (target % i != 0) continue;
		local.emplace_back(i);
		local.emplace_back(target/i);
		result.emplace_back(local);
		local.pop_back();
		dfs(target/i, i, local, result);
		local.pop_back();
	}
}

vector<vector<int>> Solution::getFactors(int n) {
	vector<vector<int>> result;
	vector<int> local;
	dfs(n, 2, local, result);
	return result;
}
