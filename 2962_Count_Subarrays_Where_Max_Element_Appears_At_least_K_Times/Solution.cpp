#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

long long Solution::countSubarrays(vector<int> &nums, int k) {
	long long result = 0;
	int maxVal = 0;
	for (const auto &v : nums)
		maxVal = max(maxVal, v);
	int l = 0;
	int cnt = 0;

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == maxVal)
			++cnt;

		while (l <= i && cnt == k) {
			if (nums[l] == maxVal)
				--cnt;
			++l;
		}

		result += l;
	}
	return result;
}
