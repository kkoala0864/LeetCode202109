#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::min;
using std::unordered_map;

int Solution::minSubarray(vector<int>& nums, int p) {
	unordered_map<int, int> mod;

	int cur = 0;
	for (const auto& v : nums) {
		cur += (v % p);
		cur %= p;
	}
	int target = cur % p;
	if (target == 0) return 0;

	cur = 0;
	int result = nums.size();
	for (int i = 0 ; i < nums.size() ; ++i) {
		cur += (nums[i] % p);
		cur %= p;
		if (cur == target) result = min(result, i + 1);

		int idx = (cur - target + p) % p;
		if (mod.count(idx)) {
			result = min(result, i - mod[idx]);
		}

		mod[cur] = i;
	}
	return result == nums.size() ? -1 : result;
}
