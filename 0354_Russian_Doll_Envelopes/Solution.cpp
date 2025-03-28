#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::maxEnvelopes(vector<vector<int>> &envelopes) {
	auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
		return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
	};

	sort(envelopes.begin(), envelopes.end(), cmp);

	vector<int> list;

	for (int i = 0; i < envelopes.size(); ++i) {
		int idx = lower_bound(list.begin(), list.end(), envelopes[i][1]) - list.begin();

		if (idx == list.size()) {
			list.emplace_back(envelopes[i][1]);
		} else {
			list[idx] = envelopes[i][1];
		}
	}
	return list.size();
}
