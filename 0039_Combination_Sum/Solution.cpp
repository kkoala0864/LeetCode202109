#include <Solution.h>
#include <iostream>

void recur(vector<int> &candidates, int target, vector<int> &tmpResult, vector<vector<int>> &result) {
	if (0 > target)
		return;
	if (0 == target) {
		if (!tmpResult.empty())
			result.emplace_back(tmpResult);
		return;
	}
	if (0 < target && candidates.empty())
		return;

	tmpResult.emplace_back(candidates.back());
	recur(candidates, target - candidates.back(), tmpResult, result);
	tmpResult.pop_back();
	int backVal = candidates.back();
	candidates.pop_back();
	recur(candidates, target, tmpResult, result);
	candidates.push_back(backVal);
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
	vector<int> tmpResult;
	vector<vector<int>> result;
	recur(candidates, target, tmpResult, result);
	return result;
}
