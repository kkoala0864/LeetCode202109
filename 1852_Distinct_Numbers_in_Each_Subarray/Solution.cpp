#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<int> Solution::distinctNumbers(vector<int>& nums, int k) {
	vector<int> result;
	vector<int> cnt(1e5 + 1, 0);
	int curCnt = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		++cnt[nums[i]];
		if (cnt[nums[i]] == 1) ++curCnt;

		if (i >= k) {
			--cnt[nums[i-k]];
			if (cnt[nums[i-k]] == 0) --curCnt;
		}
		if (i >= k-1) {
			result.emplace_back(curCnt);
		}
	}
	return result;
}
