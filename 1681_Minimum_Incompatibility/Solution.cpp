#include <Solution.h>

int Solution::minimumIncompatibility(vector<int>& nums, int k) {
	unordered_map<int, int> cnt;
	for (const auto& v : nums) {
		++cnt[v];
		if (cnt[v] > k) return -1;
	}
	int full = (1 << nums.size());
	sort(nums.begin(), nums.end());
	int psize = nums.size() / k;
	vector<int> cost(full, -1);

	for (int i = 0 ; i < full ; ++i) {
		if (__builtin_popcount(i) != psize) continue;
		int low = INT_MAX, high = INT_MIN;
		unordered_set<int> us;

		int j = 0;
		for (; j < nums.size() ; ++j) {
			if ((i & (1 << j)) == 0) continue;
			if (us.count(nums[j])) {
				break;
			}
			us.emplace(nums[j]);
			low = min(low, nums[j]);
			high = max(high, nums[j]);
		}
		if (j == nums.size()) {
			cost[i] = high - low;
		}
	}
	vector<int> dp(full, INT_MAX);
	dp[0] = 0;
	for (int mask = 0 ; mask < full ; ++mask) {
		if (dp[mask] == INT_MAX) continue;
		int rest = full -1 - mask;
		if (rest == 0) continue;
		int first = __builtin_ctz(rest);
		for (int sub = rest ; sub ; sub = (sub-1) & rest) {
			if ((sub & (1 << first)) == 0) continue;
			if (cost[sub] == -1) continue;
			dp[mask | sub] = min(dp[mask | sub], dp[mask] + cost[sub]);
		}
	}
	return dp[full-1];
}
