#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int dfs(const vector<int>& nums, int idx, long diff, int lastVal, vector<unordered_map<long, int>>& cache) {
	if (idx == nums.size()) return 0;
	if (cache[idx].count(diff) > 0) return cache[idx][diff];

	int local = 0;
	for (int i = idx ; i < nums.size() ; ++i) {
		long curDiff = (long)nums[i] - (long)lastVal;
		if (curDiff == diff) {
			local += 1;
			local += dfs(nums, i + 1, diff, nums[i], cache);
		}
	}
	cache[idx][diff] = local;
	return local;
}

int Solution::numberOfArithmeticSlices(vector<int>& nums) {
	int result = 0;
	int size = nums.size();
	vector<int> local;
	vector<unordered_map<long, int>> dp(size);
	for (int i = 0 ; i < size - 2 ; ++i) {
		for (int j = i + 1 ; j < size - 1 ; ++j) {
			long diff = (long)nums[j] - (long)nums[i];
			result += dfs(nums, j + 1, diff, nums[j], dp);
		}
	}
	return result;
}

int Solution::Standard(vector<int>& nums) {
	int size = nums.size();
	int result = 0;

	vector<unordered_map<long long, int>> dp(size);
	for (int i = 1 ; i < size ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			long long diff = (long long)nums[i] - (long long)nums[j];
			int sum = 0;
			if (dp[j].find(diff) != dp[j].end()) {
				sum = dp[j][diff];
			}
			dp[i][diff] += sum + 1;
			result += sum;
		}
	}
	return result;
}
