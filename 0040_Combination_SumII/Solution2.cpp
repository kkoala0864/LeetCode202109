#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

void construct(const vector<int> &candidates, vector<int> &local, int cur, int target, vector<vector<int>> &result) {
	if (target < 0)
		return;
	if (target == 0) {
		result.emplace_back(local);
		return;
	}

	for (int i = cur; i < candidates.size(); ++i) {
		if (candidates[i] > target)
			break;
		local.emplace_back(candidates[i]);
		construct(candidates, local, i + 1, target - candidates[i], result);
		local.pop_back();
		while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
			++i;
	}
}

vector<vector<int>> Solution::combinationSum2(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> local;
	construct(candidates, local, 0, target, result);
	return result;
}
