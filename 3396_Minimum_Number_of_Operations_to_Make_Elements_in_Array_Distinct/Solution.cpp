#include <Solution.h>
#include <iostream>
#include <unordered_map>

int Solution::minimumOperations(vector<int> &nums) {
	unordered_map<int, int> cnt;
	int dupCnt = 0;
	for (const auto &v : nums) {
		++cnt[v];
		if (cnt[v] == 2) ++dupCnt;
	}
	if (dupCnt == 0) return 0;

	int maxLoop = nums.size() / 3;
	for (int i = 0; i < maxLoop; ++i) {
		for (int j = 0; j < 3; ++j) {
			--cnt[nums[i * 3 + j]];
			if (cnt[nums[i * 3 + j]] == 1) --dupCnt;
			if (dupCnt == 0) return i + 1;
		}
	}
	return dupCnt == 0 ? maxLoop : maxLoop + 1;
}
