#include <Solution.h>

int Solution::maxSubarraySumCircular(vector<int>& nums) {
	int size = nums.size();
	int result = INT_MIN;
	int total = 0;
	int minEnd = 0, maxEnd = 0;
	int maxSum = INT_MIN, minSum = INT_MAX;
	for (const auto& v : nums) {
		total += v;

		maxEnd = max(v, maxEnd + v);
		maxSum = max(maxSum, maxEnd);

		minEnd = min(v, minEnd + v);
		minSum = min(minSum, minEnd);
	}
	if (maxSum < 0) return maxSum;
	return max(total - minSum, maxSum);
}
