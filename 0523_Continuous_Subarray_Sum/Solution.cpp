#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::checkSubarraySum(vector<int> &nums, int k) {
	unordered_map<int, int> m;

	int mod = 0;
	for (int i = 0; i < nums.size(); ++i) {
		mod += nums[i];
		mod %= k;
		if (i >= 1 && mod == 0)
			return true;
		if (m.count(mod) && (i - m[mod]) > 1)
			return true;
		if (m.count(mod) == 0)
			m[mod] = i;
	}
	return false;
}
