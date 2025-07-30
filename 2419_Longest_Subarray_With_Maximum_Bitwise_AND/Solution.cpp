#include <Solution.h>

int Solution::longestSubarray(vector<int> &nums) {
	int mx = 0;
	for (const auto& v : nums) mx = max(mx, v);

	int result = 0;
	int cur = 0;
	for (const auto& v : nums) {
		if (v == mx) {
			++cur;
			result = max(result, cur);
		} else {
			cur = 0;
		}
	}
	return result;
}
