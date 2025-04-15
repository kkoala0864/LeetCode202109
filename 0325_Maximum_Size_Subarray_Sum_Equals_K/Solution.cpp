#include <Solution.h>
#include <iostream>
#include <unordered_map>

int Solution::maxSubArrayLen(vector<int> &nums, int k) {
	unordered_map<long long, int> m;

	long long sum = 0;
	m[0] = -1;
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		sum += (long long)nums[i];
		// sum - x = k
		// sum - k = x
		long long target = sum - k;
		if (m.count(target)) {
			result = max(result, i - m[target]);
		}
		if (m.count(sum) == 0) m[sum] = i;
	}
	return result;
}

