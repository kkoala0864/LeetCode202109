#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::max;
using std::cout;
using std::endl;

bool cmp(vector<int>& lhs, vector<int>& rhs) {
	return lhs[0] == rhs[0] ? rhs[1] < lhs[1] : lhs[0] < rhs[0];
}

int bSearch(vector<int>& dp, int num) {
	int l = 0, r = dp.size() - 1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (dp[m] == num) return m;
		else if (dp[m] > num) r = m - 1;
		else l = m + 1;
	}
	return l;
}

int LengthOfLIS(vector<int>& vec) {
	vector<int> dp;
	for (int i = 0 ; i < vec.size() ; ++i) {
		int idx = bSearch(dp, vec[i]);
		if (idx == dp.size()) dp.emplace_back(vec[i]);
		else dp[idx] = vec[i];
	}
	return dp.size();
}

int Solution::maxEnvelopes(vector<vector<int>>& envelopes) {
	sort(envelopes.begin(), envelopes.end(), cmp);
	vector<int> vec(envelopes.size(), 0);
	for (int i = 0 ; i < envelopes.size() ; ++i) vec[i] = envelopes[i][1];
	return LengthOfLIS(vec);
}
