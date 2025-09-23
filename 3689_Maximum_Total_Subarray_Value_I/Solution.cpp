#include <Solution.h>

long long Solution::maxTotalValue(vector<int>& nums, int k) {
	int mn = INT_MAX;
	int mx = INT_MIN;
	for (const auto& v : nums) {
		mn = min(v, mn);
		mx = max(v, mx);
	}

	long long v = mx - mn;
	return v * k;
}
