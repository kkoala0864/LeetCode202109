#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

// sum - x = goal
// sum - goal = x
int Solution::numSubarraysWithSum(vector<int> &nums, int goal) {
	unordered_map<int, int> m;
	int sum = 0;
	int result = 0;
	m[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
		sum += nums[i];
		if (m.count(sum - goal)) {
			result += m[sum - goal];
		}
		++m[sum];
	}
	return result;
}
