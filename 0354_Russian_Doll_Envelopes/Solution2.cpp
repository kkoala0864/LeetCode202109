#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int findMinimalLargeThan(vector<int>& dp, int val) {
	int l = 0, r = dp.size() - 1;
	int mid = 0;
	while (l <= r) {
		mid = (l+r) >> 1;
		if (dp[mid] == val) {
			return mid;
		} else if (dp[mid] < val) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

int Solution::maxEnvelopes2(vector<vector<int>>& envelopes) {
	auto cmp = [] (vector<int>& lhs, vector<int>& rhs) { return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0]; };
	sort(envelopes.begin(), envelopes.end(), cmp);
	vector<int> dp(1, envelopes[0][1]);
	for (int i = 1 ; i < envelopes.size() ; ++i) {
		int idx = findMinimalLargeThan(dp, envelopes[i][1]);
		if (idx == dp.size()) dp.emplace_back(envelopes[i][1]);
		else dp[idx] = envelopes[i][1];
	}
	return dp.size();
}
