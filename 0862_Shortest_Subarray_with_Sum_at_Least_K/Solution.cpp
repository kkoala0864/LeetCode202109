#include <Solution.h>
#include <deque>

int Solution::shortestSubarray(vector<int>& nums, int k) {
	vector<long long> preSum(1, 0);
	for (int i = 0 ; i < nums.size() ; ++i) {
		preSum.emplace_back(preSum.back() + (long long)nums[i]);
	}

	deque<int> dq;
	dq.emplace_back(0);
	int result = INT_MAX;
	for (int i = 1 ; i < preSum.size() ; ++i) {
		while (!dq.empty() && preSum[dq.back()] > preSum[i]) {
			dq.pop_back();
		}
		while (!dq.empty() && (preSum[i] - preSum[dq.front()]) >= k) {
			result = min(result, i - dq.front());
			dq.pop_front();
		}
		dq.emplace_back(i);
	}
	return result == INT_MAX ? -1 : result;
}
