#include <Solution.h>

int Solution::maximumUniqueSubarray(vector<int> &nums) {
	unordered_set<int> us;
	int l = 0;
	int result = 0;
	int sum = 0;
	for (int r = 0 ; r < nums.size() ; ++r) {
		while (l <= r && us.count(nums[r])) {
			sum -= nums[l];
			us.erase(nums[l]);
			++l;
		}
		sum += nums[r];
		us.emplace(nums[r]);
		result = max(result, sum);
	}
	return result;
}
