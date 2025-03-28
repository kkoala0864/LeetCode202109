#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;

int getV(vector<int> &cnt) {
	int result = 0;
	for (int i = 0; i < 32; ++i) {
		if (cnt[i] > 0) {
			result = result | (1 << i);
		}
	}
	return result;
}

void updateCnt(vector<int> &cnt, int v, int delta) {
	for (int i = 0; i < 32; ++i) {
		if ((1 << i) & v)
			cnt[i] += delta;
	}
}

int Solution::minimumSubarrayLength(vector<int> &nums, int k) {
	int result = INT_MAX;
	vector<int> cnt(32, 0);

	int j = 0;
	for (int i = 0; i < nums.size(); ++i) {
		updateCnt(cnt, nums[i], 1);
		for (; j <= i && getV(cnt) >= k; ++j) {
			result = min(result, i - j + 1);
			updateCnt(cnt, nums[j], -1);
		}
	}
	return result == INT_MAX ? -1 : result;
}
