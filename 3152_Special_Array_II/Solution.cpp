#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

vector<bool> Solution::isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
	vector<int> failedInterval;

	for (int i = 0 ; i < nums.size() - 1 ; ++i) {
		if ((nums[i] & 1) != (nums[i + 1] & 1)) continue;
		failedInterval.push_back(i);
	}
	vector<bool> result;
	for (const auto& q : queries) {
		if (q[0] == q[1]) {
			result.push_back(true);
			continue;
		}
		int idx = lower_bound(failedInterval.begin(), failedInterval.end(), q[0]) - failedInterval.begin();
		if (idx == failedInterval.size()) result.push_back(true);
		else {
			result.push_back(failedInterval[idx]+1 > q[1]);
		}
	}
	return result;
}
