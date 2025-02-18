#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;
using std::max;
using std::min;

bool Solution::maxSubstringLength(string s, int k) {
	if (k == 0) return true;
	vector<pair<int, int>> se(26, pair<int, int>(INT_MAX, INT_MIN));

	for (int i = 0 ; i < s.size() ; ++i) {
		se[s[i]-'a'].first = min(se[s[i]-'a'].first, i);
		se[s[i]-'a'].second = max(se[s[i]-'a'].second, i);
	}

	vector<bool> check(26, true);
	for (int i = 0 ; i < 26 ; ++i) {
		if (se[i].first == INT_MAX) continue;
		int idx = se[i].first;
		int end = se[i].second;
		while (idx < se[i].second) {
			if (se[s[idx]-'a'].first < se[i].first) {
				check[i] = false;
				break;
			}
			se[i].second = max(se[i].second, se[s[idx]-'a'].second);
			++idx;
		}
	}

	vector<pair<int, int>> intervals;
	for (int i = 0 ; i < 26 ; ++i) {
		if (se[i].first == INT_MAX || !check[i]) continue;
		if (se[i].first == 0 && se[i].second == s.size() - 1) continue;
		intervals.emplace_back(se[i]);
	}
	if (intervals.empty()) return false;

	auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return lhs.second < rhs.second;
	};
	sort(intervals.begin(), intervals.end(), cmp);

	int end = INT_MIN;
	int cnt = 0;
	for (int i = 0 ; i < intervals.size() ; ++i) {
		if (intervals[i].first > end) {
			end = intervals[i].second;
			++cnt;
		}
	}
	return cnt >= k;
}
