#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::numSubseq(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());

	int result = 0;
	int mod = 1e9 + 7;
	vector<int> power(nums.size() + 1, 0);
	for (int i = 0; i < nums.size(); ++i) {
		power[i + 1] = (power[i] * 2) % mod;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > target)
			break;
		int rest = target - nums[i];
		if (rest < nums[i])
			break;

		int idx = lower_bound(nums.begin(), nums.end(), rest) - nums.begin();
		if (idx == nums.size() || nums[idx] > rest)
			--idx;
		while (idx < nums.size() - 1 && nums[idx + 1] <= rest)
			++idx;
		int len = idx - i;

		result += power[len];
		result %= mod;
	}
	return result;
}
