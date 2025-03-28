#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::max;
using std::pair;

long long Solution::maximumTotalDamage(vector<int> &power) {
	map<long long, long long> m;
	vector<pair<long long, long long>> l;
	for (const auto &p : power)
		++m[p];
	for (const auto &e : m) {
		l.emplace_back(pair<long long, long long>(e.first, e.first * e.second));
	}
	vector<long long> dp(l.size(), 0);

	dp[0] = l[0].second;
	long long result = dp[0];
	long long preMax = dp[0];
	long long preIdx = 0;

	for (int i = 1; i < l.size(); ++i) {
		while ((l[i].first - l[preIdx + 1].first) > 2) {
			++preIdx;
			preMax = max(preMax, dp[preIdx]);
		}
		dp[i] = l[i].second;
		if ((l[i].first - l[preIdx].first) > 2) {
			dp[i] += preMax;
		}
		result = max(result, dp[i]);
	}
	return result;
}
