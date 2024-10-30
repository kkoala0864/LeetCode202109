#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::cout;
using std::endl;

int Solution::minimumMountainRemovals(vector<int>& nums) {
	vector<int> pre, post(nums.size(), 0);

	vector<int> list;
	for (int i = 0 ; i < nums.size() ; ++i) {
		int idx = lower_bound(list.begin(), list.end(), nums[i]) - list.begin();
		if (idx == list.size()) {
			list.emplace_back(nums[i]);
		} else {
			list[idx] = nums[i];
		}
		pre.emplace_back(list.size());
	}
	list.clear();
	for (int i = nums.size() - 1 ; i >= 0 ; --i) {
		int idx = lower_bound(list.begin(), list.end(), nums[i]) - list.begin();
		if (idx == list.size()) {
			list.emplace_back(nums[i]);
		} else {
			list[idx] = nums[i];
		}
		post[i] = list.size();
	}
	int result = nums.size();
	for (int i = 1 ; i < nums.size() - 1 ; ++i) {
		int len = pre[i] + post[i] - 1;
		if (pre[i] < 2 || post[i] < 2 || len < 3) continue;
		result = min(result, (int)nums.size() - len);
	}
	return result;
}
