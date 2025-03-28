#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <map>

using std::map;
using std::max;

int Solution::maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
	map<int, int> m;
	for (int i = 0; i < difficulty.size(); ++i) {
		m[difficulty[i]] = m[difficulty[i]] > 0 ? max(m[difficulty[i]], profit[i]) : profit[i];
	}

	int cur = INT_MIN;
	for (auto &e : m) {
		cur = max(cur, e.second);
		e.second = cur;
	}

	int result = 0;
	for (const auto &w : worker) {
		auto iter = m.lower_bound(w);
		if (iter == m.end()) {
			--iter;
		} else if (iter->first > w) {
			if (iter == m.begin())
				continue;
			--iter;
		}
		result += iter->second;
	}
	return result;
}
