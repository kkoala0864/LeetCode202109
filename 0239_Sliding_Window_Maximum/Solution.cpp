#include <Solution.h>

vector<int> Solution::maxSlidingWindow(vector<int> &nums, int k) {
	deque<int> deq;
	vector<int> result;
	for (int i = 0 ; i < nums.size() ; ++i) {
		while (!deq.empty() && nums[deq.back()] <= nums[i]) {
			deq.pop_back();
		}
		while (!deq.empty() && deq.front() <= (i - k)) {
			deq.pop_front();
		}
		deq.emplace_back(i);
		if (i >= k-1) {
			result.emplace_back(nums[deq.front()]);
		}
	}
	return result;

}
