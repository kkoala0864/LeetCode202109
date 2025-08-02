#include <Solution.h>

long long Solution::minCost(vector<int>& basket1, vector<int>& basket2) {
	unordered_map<long long, int> cnt1, cnt2, cnt;
	long long minV = INT_MAX;

	for (const auto& v : basket1) {
		++cnt1[v];
		++cnt[v];
		minV = min(minV, (long long)v);
	}
	for (const auto& v : basket2) {
		++cnt2[v];
		++cnt[v];
		minV = min(minV, (long long)v);
	}
	for (auto& e : cnt) {
		if (e.second & 1) return -1;
		e.second >>= 1;
	}
	vector<long long> c;
	for (const auto& e : cnt1) {
		if (e.second > cnt[e.first]) {
			for (int i = 0 ; i < (e.second - cnt[e.first]) ; ++i) {
				c.emplace_back(e.first);
			}
		}
	}
	for (const auto& e : cnt2) {
		if (e.second > cnt[e.first]) {
			for (int i = 0 ; i < (e.second - cnt[e.first]) ; ++i) {
				c.emplace_back(e.first);
			}
		}
	}
	sort(c.begin(), c.end());
	long long result = 0;
	for (int i = 0 ; i < (c.size() / 2) ; ++i) {
		long long dc = c[i];
		long long ic = 2 * minV;
		result += min(dc, ic);
	}
	return result;
}
