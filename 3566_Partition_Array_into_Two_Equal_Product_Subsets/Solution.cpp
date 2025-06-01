#include <Solution.h>

bool Solution::checkEqualPartitions(vector<int>& nums, long long target) {
	unsigned long long total = 1;
	for (const auto& v : nums) {
		total *= v;
	}
	if (total != (unsigned long long) target * (unsigned long long) target) return false;

	sort(nums.begin(), nums.end());
	unordered_set<long long> dp;
	dp.emplace(1);
	for (const auto& v : nums) {
		auto next = dp;
		for (const auto& n : dp) {
			next.emplace(n * v);
		}
		dp = move(next);
		if (dp.count(target)) return true;
	}
	return false;
}
