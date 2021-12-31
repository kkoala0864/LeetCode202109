#include <Solution.h>
#include <iostream>

void combination(vector<int>& candidates, int target, int idx, vector<int>& local, vector<vector<int>>& result) {
	if (target == 0) {
		result.emplace_back(local);
		return;
	}

	for (int i = idx ; i < candidates.size() ; ++i) {
		if (candidates[i] <= target) {
			local.emplace_back(candidates[i]);
			combination(candidates, target-candidates[i], i, local, result);
			local.pop_back();
		}
	}
}

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
	vector<int> local;
	vector<vector<int>> result;
	combination(candidates, target, 0, local, result);
	return result;
}
