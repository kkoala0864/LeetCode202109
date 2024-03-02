#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::deleteAndEarn2(vector<int>& nums) {
	vector<int> m(10001, 0);

	int mVal = 0;
	for (const auto& v : nums) {
		++m[v];
		mVal = max(mVal, v);
	}

	int prev1 = 0;
	int prev2 = 0;
	int cur = 0;
	for (int i = 1 ; i <= mVal ; ++i) {
		cur = max(prev1, prev2 + i * m[i]);
		prev2 = prev1;
		prev1 = cur;
	}
	return cur;
}
