#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

void dfs(const vector<int>& candidates, int start, int target, vector<int>& localResult, vector<vector<int>>& result) {
	if (target < 0) return;
	if (target == 0) {
		result.emplace_back(localResult);
		return;
	}

	for (int i = start ; i < candidates.size() ; ++i) {
		if (target < candidates[i]) continue;
		localResult.emplace_back(candidates[i]);
		dfs(candidates, i + 1, target - candidates[i], localResult, result);
		while (i < candidates.size()-1 && candidates[i] == candidates[i+1]) {
			++i;
		}
		localResult.pop_back();
	}
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> localResult;
	dfs(candidates, 0, target, localResult, result);
	return result;
}
