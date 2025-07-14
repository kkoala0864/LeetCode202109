#include <Solution.h>

long long Solution::maxAlternatingSum(vector<int>& nums) {
	pair<long long, long long> dp(0, 0);

	for (int i = 0 ; i < nums.size() ; ++i) {
		pair<long long, long long> next = dp;
		next.first = max(next.first, dp.second + nums[i]);
		next.second = max(next.second, dp.first - nums[i]);
		dp = std::move(next);
	}
	return max(dp.first, dp.second);
}
