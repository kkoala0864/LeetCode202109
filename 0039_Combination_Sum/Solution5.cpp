#include <Solution.h>
#include <iostream>

void recur(vector<int>& candidates, int target, vector<int>& local, int idx, vector<vector<int>>& result) {
	if (target < 0) return;
	if (target == 0) {
		result.emplace_back(local);
		return;
	}

	for (int i = idx ; i < candidates.size() ; ++i) {
		local.emplace_back(candidates[i]);
		recur(candidates, target - candidates[i], local, i, result);
		local.pop_back();
	}
}

vector<vector<int>> Solution::combinationSum5(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	vector<int> local;
	recur(candidates, target, local, 0, result);
	return result;
}
