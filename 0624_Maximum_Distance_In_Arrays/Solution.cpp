#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::pair;

int Solution::maxDistance(vector<vector<int>>& arrays) {
	vector<pair<int, int>> s;
	vector<pair<int, int>> b;

	for (int i = 0 ; i < arrays.size() ; ++i) {
		s.emplace_back(pair<int, int>(arrays[i][0], i));
		b.emplace_back(pair<int, int>(arrays[i].back(), i));

		sort(s.begin(), s.end());
		sort(b.begin(), b.end(), std::greater<pair<int, int>>());
		while (s.size() > 2) {
			s.pop_back();
		}
		while (b.size() > 2) {
			b.pop_back();
		}
	}

	int result = 0;
	for (int i = 0 ; i < 2 ; ++i) {
		for(int j = 0 ; j < 2; ++j) {
			if (s[i].second == b[j].second) continue;
			result = max(result, b[j].first - s[i].first);
		}
	}
	return result;
}
