#include <Solution.h>
#include <iostream>
#include <unordered_map>

long long Solution::countGood(vector<int>& nums, int k) {
	unordered_map<int, int> cnt;

	long long curPairCnt = 0;

	long long result = 0;
	int l = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		++cnt[nums[i]];
		curPairCnt += (cnt[nums[i]] - 1);

		while (curPairCnt >= k) {
			result += (nums.size() - i);
			--cnt[nums[l]];
			curPairCnt -= cnt[nums[l]];
			++l;
		}
	}
	while (curPairCnt >= k) {
		result += 1;
		--cnt[nums[l]];
		curPairCnt -= cnt[nums[l]];
		++l;
	}
	return result;
}
