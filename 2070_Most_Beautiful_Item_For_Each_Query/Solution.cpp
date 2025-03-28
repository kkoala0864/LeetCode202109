#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<int> Solution::maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
	sort(items.begin(), items.end());
	vector<int> p, b;

	int curMaxB = INT_MIN;
	for (int i = 0; i < items.size(); ++i) {
		curMaxB = max(curMaxB, items[i][1]);
		if (p.empty() || p.back() != items[i][0]) {
			p.emplace_back(items[i][0]);
			b.emplace_back(curMaxB);
		} else {
			b.back() = curMaxB;
		}
	}
	vector<int> result;
	for (const auto &q : queries) {
		int idx = upper_bound(p.begin(), p.end(), q) - p.begin();
		if (idx == 0) {
			result.emplace_back(0);
		} else {
			--idx;
			result.emplace_back(b[idx]);
		}
	}
	return result;
}
