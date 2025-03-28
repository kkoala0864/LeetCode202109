#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

using std::max;
using std::unordered_map;

int Solution::largestInteger(vector<int> &nums, int k) {
	if (nums.size() == k) {
		int maxVal = INT_MIN;
		for (const auto &v : nums)
			maxVal = max(maxVal, v);
		return maxVal;
	} else {
		unordered_map<int, int> cnt;

		for (int i = 0; i < k - 1; ++i)
			cnt[nums[i]] += (i + 1);
		for (int i = k - 1; i < (nums.size() - k + 1); ++i) {
			cnt[nums[i]] += k;
		}
		for (int i = nums.size() - k + 1; i < nums.size(); ++i) {
			cnt[nums[i]] += (nums.size() - i);
		}
		int result = INT_MIN;
		for (const auto &e : cnt)
			if (e.second == 1)
				result = max(result, e.first);
		return result == INT_MIN ? -1 : result;
	}
}
