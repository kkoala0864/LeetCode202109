#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::max;

bool check(vector<pair<int, int>>& list) {
	vector<pair<int, int>> interval;
	for (int i = 0 ; i < list.size() ; ++i) {
		if (interval.empty() || interval.back().second <= list[i].first) {
			interval.emplace_back(list[i]);
		} else {
			interval.back().second = max(interval.back().second, list[i].second);
		}
	}
	return interval.size() >= 3;
}

bool Solution::checkValidCuts(int n, vector<vector<int>>& rectangles) {
	vector<pair<int, int>> xI;
	vector<pair<int, int>> yI;

	for (const auto& r : rectangles) {
		xI.emplace_back(pair<int, int>(r[0], r[2]));
		yI.emplace_back(pair<int, int>(r[1], r[3]));
	}
	sort(xI.begin(), xI.end());
	sort(yI.begin(), yI.end());
	return check(xI) || check(yI);
}
