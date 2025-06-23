#include <Solution.h>

int Solution::maxSubarrayLength(vector<int> &nums, int k) {
	unordered_map<int, int> cnt;

	int result = 0;
	int l = 0;
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
