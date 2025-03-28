#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

using std::max;
using std::unordered_map;

int Solution::maxSubArrayLen(vector<int> &nums, int k) {
	int size = nums.size();
	unordered_map<int, int> uMap;
	int sum = 0;
	int result = 0;

	for (int i = 0; i < size; ++i) {
		sum += nums[i];

		if (uMap.find(sum) == uMap.end())
			uMap[sum] = i;

		if (sum == k)
			result = max(result, i + 1);
		if (uMap.find(sum - k) != uMap.end()) {
			result = max(result, i - uMap[sum - k]);
		}
	}

	return result;
}
