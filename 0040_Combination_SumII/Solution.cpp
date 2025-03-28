#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

void recur(vector<int> &candidates, int idx, int sum, int target, vector<int> &cur, vector<vector<int>> &result) {
	if (sum > target)
		return;
	if (sum == target) {
		result.emplace_back(cur);
		return;
	}
	if (idx >= candidates.size())
		return;

	for (int i = idx; i < candidates.size(); ++i) {
		cur.emplace_back(candidates[i]);
		recur(candidates, i + 1, sum + candidates[i], target, cur, result);
		cur.pop_back();
		while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
			++i;
	}
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> cur;
	recur(candidates, 0, 0, target, cur, result);
	return result;
}
