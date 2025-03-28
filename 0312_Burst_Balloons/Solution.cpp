#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int find(const vector<int> &nums, vector<vector<int>> &cache, int start, int end) {
	if (start > end)
		return 0;
	if (cache[start][end] != -1)
		return cache[start][end];
	if (start == end) {
		// First burst balloon, adjust has not been burst, so it just product wirh (start-1) and (start+1) || (end-1) and (end+1)
		cache[start][end] = nums[start] * nums[start - 1] * nums[end + 1];
		return cache[start][end];
	}

	int result = 0;
	for (int k = start; k <= end; ++k) {
		// K Element is latest balloon to be burst, so [start, k-1] , [k+1, end] had been burst
		// so it should product with (start - 1) and (end + 1)
		int tmp = nums[k] * nums[start - 1] * nums[end + 1];
		tmp += find(nums, cache, start, k - 1) + find(nums, cache, k + 1, end);
		result = max(result, tmp);
	}
	cache[start][end] = result;
	return result;
}

int Solution::maxCoins(vector<int> &nums) {
	vector<vector<int>> cache(501, vector<int>(501, -1));
	vector<int> tmp(1, 1);
	for (const auto &iter : nums)
		tmp.emplace_back(iter);
	tmp.emplace_back(1);
	int result = find(tmp, cache, 1, tmp.size() - 2);
	return result;
}
