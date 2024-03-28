#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int Solution::maxSubarrayLength(vector<int>& nums, int k) {
	unordered_map<int, int> cnt;

	int l = 0;
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		++cnt[nums[i]];

		while (l < i && cnt[nums[i]] > k) {
			--cnt[nums[l]];
			++l;
		}
		result = max(result, i - l + 1);
	}
	return result;
}
