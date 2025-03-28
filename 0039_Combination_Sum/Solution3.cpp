#include <Solution.h>
#include <iostream>

void combineSum(const vector<int> &candidates, int target, vector<int> &local, vector<vector<int>> &result, int idx) {
	if (target < 0)
		return;
	if (target == 0) {
		result.emplace_back(local);
		return;
	}

	for (int i = idx; i < candidates.size(); ++i) {
		local.emplace_back(candidates[i]);
		combineSum(candidates, target - candidates[i], local, result, i);
		local.pop_back();
	}
}

vector<vector<int>> Solution::combinationSum3(vector<int> &candidates, int target) {
	vector<vector<int>> result;
	vector<int> local;
	combineSum(candidates, target, local, result, 0);
	return result;
}
/*
 * DP Version
vector<vector<int>> Solution::combinationSum3(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>());
        dp[0].push_back({});
        for (const auto& candidate : candidates) {
                for (int j = candidate ; j <= target ; ++j) {
                        for (auto& ele : dp[j-candidate]) {
                                vector<int> tmp = ele;
                                tmp.emplace_back(candidate);
                                dp[j].emplace_back(tmp);
                        }
                }
        }
        return dp[target];
}*/
