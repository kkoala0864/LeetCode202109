#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int getF(const string &s) {
	vector<int> cnt(26, 0);
	for (const auto &c : s) {
		++cnt[c - 'a'];
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] != 0)
			return cnt[i];
	}
	return 0;
}

vector<int> Solution::numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
	vector<int> qF, wF;
	for (const auto &q : queries) {
		qF.emplace_back(getF(q));
	}
	for (const auto &w : words) {
		wF.emplace_back(getF(w));
	}
	sort(wF.begin(), wF.end());
	vector<int> result;
	for (const auto &q : qF) {
		int idx = upper_bound(wF.begin(), wF.end(), q) - wF.begin();

		result.emplace_back(wF.size() - idx);
	}
	return result;
}
