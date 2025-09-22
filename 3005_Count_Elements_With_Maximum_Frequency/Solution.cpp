#include <Solution.h>

int Solution::maxFrequencyElements(vector<int> &nums) {
	unordered_map<int, int> cnt;
	int mxCnt = 0;

	for (const auto& v : nums) {
		++cnt[v];
		mxCnt = max(mxCnt, cnt[v]);
	}
	int result = 0;
	for (const auto& e : cnt) {
		if (e.second == mxCnt) result += mxCnt;
	}
	return result;
}
