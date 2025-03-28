#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

bool check(vector<int> &nums, vector<long long> &preSum, int k, int size) {
	bool find = false;
	for (int i = size - 1; i < nums.size(); ++i) {
		long long curSum = preSum[i];
		if (i >= size) {
			curSum -= preSum[i - size];
		}
		if ((((long long)size * (long long)nums[i]) - curSum) <= k) {
			find = true;
			break;
		}
	}
	return find;
}

int Solution::maxFrequency(vector<int> &nums, int k) {
	sort(nums.begin(), nums.end());

	int l = 1, r = nums.size();
	int mid = 0;
	vector<long long> preSum;
	long long sum = 0;
	for (const auto &v : nums) {
		sum += v;
		preSum.emplace_back(sum);
	}

	while (l < r) {
		mid = l + ((r - l) / 2);
		if (check(nums, preSum, k, mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return check(nums, preSum, k, l) ? l : l - 1;
}
