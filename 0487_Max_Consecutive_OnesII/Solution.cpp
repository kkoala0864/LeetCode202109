#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::findMaxConsecutiveOnes(vector<int>& nums) {
	vector<int> val;
	vector<int> cnt;

	val.emplace_back(nums[0]);
	cnt.emplace_back(1);
	for (int i = 1 ; i < nums.size() ; ++i) {
		if (nums[i] == val.back()) {
			++cnt.back();
		} else {
			val.emplace_back(nums[i]);
			cnt.emplace_back(1);
		}
	}

	int result = 1;
	for (int i = 0 ; i < val.size() ; ++i) {
		if (val[i] == 0 && cnt[i] == 1) {
			int cur = 1;
			if (i > 0) {
				cur += cnt[i-1];
			}
			if (i < val.size() - 1) {
				cur += cnt[i+1];
			}
			result = max(result, cur);
		} else {
			if (val[i] == 1) {
				if (cnt[i] == nums.size()) return nums.size();
				else result = max(result, cnt[i] + 1);
			}
		}
	}
	return result;
}
