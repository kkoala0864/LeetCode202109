#include <Solution.h>

int Solution::maxValue(vector<vector<int>>& events, int k) {
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};
	sort(events.begin(), events.end(), cmp);

	int result = 0;
	map<int, int> dp;
	dp[0] = 0;
	for (int i = 0 ; i < k ; ++i) {
		map<int, int> next;
		next[0] = 0;
		int last = 0;
		for (const auto& e : events) {
			auto sIter = dp.lower_bound(e[0]);
			--sIter;
			int v = sIter->second + e[2];
			last = next[e[1]] = max(last, v);
			result = max(result, next[e[1]]);
		}
		dp = move(next);
	}
	return result;
}
