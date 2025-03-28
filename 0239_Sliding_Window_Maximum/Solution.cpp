#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::map;
using std::max;
using std::min;

vector<int> Solution::maxSlidingWindow(vector<int> &nums, int k) {
	vector<int> result;
	map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		++m[nums[i]];
		if (i >= k - 1) {
			result.push_back(m.rbegin()->first);
			--m[nums[i - (k - 1)]];
			if (m[nums[i - (k - 1)]] == 0)
				m.erase(nums[i - (k - 1)]);
		}
	}
	return result;
}

vector<int> Solution::dp(vector<int> &nums, int k) {
	int n = nums.size();
	vector<int> left(n, 0), right(n, 0);

	int start = 0, end = k - 1;
	int blockCnt = 0;
	int leftMax = INT_MIN, rightMax = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int lIdx = start + blockCnt;
		left[lIdx] = leftMax = max(leftMax, nums[lIdx]);
		int rIdx = min(n - 1, end - blockCnt);
		right[rIdx] = rightMax = max(rightMax, nums[rIdx]);
		++blockCnt;
		if (blockCnt == k) {
			blockCnt = 0;
			start += k;
			end += k;
			end = min(end, n - 1);
			leftMax = rightMax = INT_MIN;
		}
	}
	vector<int> result;
	for (int i = 0; i <= (n - k); ++i) {
		result.emplace_back(max(right[i], left[i + k - 1]));
	}
	return result;
}
