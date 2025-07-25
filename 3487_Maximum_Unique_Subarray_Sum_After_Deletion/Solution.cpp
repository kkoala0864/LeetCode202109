#include <Solution.h>

int Solution::maxSum(vector<int> &nums) {
	unordered_set<int> us;
	int maxVal = INT_MIN;
	int sum = 0;
	for (const auto& v : nums) {
		maxVal = max(maxVal, v);
		if (v > 0 && us.count(v) == 0) {
			sum += v;
			us.emplace(v);
		}
	}
	return sum > 0 ? sum : maxVal;
}
