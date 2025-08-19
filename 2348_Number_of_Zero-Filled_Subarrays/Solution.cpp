#include <Solution.h>

long long Solution::zeroFilledSubarray(vector<int>& nums) {
	long long result = 0;

	long long cur = 0;

	for (const auto& v : nums) {
		if (v != 0) {
			cur = 0;
		} else {
			++cur;
			result += cur;
		}
	}
	return result;
}
