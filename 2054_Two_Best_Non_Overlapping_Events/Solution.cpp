#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::sort;

int Solution::maxTwoEvents(vector<vector<int>> &events) {
	map<int, int> dp;
	int result = 0;

	auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};
	sort(events.begin(), events.end(), cmp);

	dp[0] = 0;
	for (const auto &e : events) {
		result = max(result, e[2]);
		dp[e[1]] = result;
	}
	for (const auto &e : events) {
		auto iter = dp.lower_bound(e[0]);
		--iter;
		result = max(result, iter->second + e[2]);
	}
	return result;
}
