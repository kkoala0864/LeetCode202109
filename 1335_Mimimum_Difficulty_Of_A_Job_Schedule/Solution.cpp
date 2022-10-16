#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::max;

// job dependent

// at least one job every day
// what's the range of joblist size ?
// what's d's range ?
// what's the range of value of jobDifficulty ?
//
// 6
//  => |6,5|    |6|,|5|

int dfs(vector<int>& nums, int d, int idx, vector<vector<int>>& cache) {
	if (cache[idx][d] != INT_MAX) return cache[idx][d];
	if (d == 0) {
		int maxVal = 0;
		for (int i = idx ; i < nums.size() - d ; ++i) maxVal = max(maxVal, nums[i]);
		cache[idx][d] = maxVal;
		return maxVal;
	}

	int minVal = INT_MAX;
	int maxVal = 0;
	for (int i = idx ; i < nums.size() - d ; ++i) {
		maxVal = max(maxVal, nums[i]);
		int nextD = dfs(nums, d-1, i + 1, cache);
		minVal = min(minVal, maxVal + nextD);
	}
	cache[idx][d] = minVal;
	return minVal;
}

int Solution::minDifficulty(vector<int>& jobDifficulty, int d) {
	if (jobDifficulty.size() < d) return -1;
	vector<vector<int>> cache(jobDifficulty.size(), vector<int>(d, INT_MAX));
	return dfs(jobDifficulty, d - 1, 0, cache);
}
