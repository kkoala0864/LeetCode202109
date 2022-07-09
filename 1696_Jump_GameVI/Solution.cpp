#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>
#include <deque>

using std::max;
using std::deque;

int Solution::maxResult(vector<int>& nums, int k) {
	vector<int> dp;
	deque<int> deq;

	dp.emplace_back(nums[0]);
	deq.emplace_back(0);

	for (int i =  1 ; i < nums.size() ; ++i) {
		while (!deq.empty() && deq.front() < i - k) {
			deq.pop_front();
		}

		dp.emplace_back(dp[deq.front()] + nums[i]);
		while (!deq.empty() && dp.back() >= dp[deq.back()]) {
			deq.pop_back();
		}
		deq.emplace_back(i);
	}
	return dp.back();
}
