#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::max;
using std::min;
using std::sort;
using std::unordered_map;
using std::unordered_set;

bool Solution::isReflected2(vector<vector<int>> &points) {
	int minX = INT_MAX, maxX = INT_MIN;
	unordered_map<int, unordered_set<double>> uMap;
	for (const auto &p : points) {
		minX = min(minX, p[0]);
		maxX = max(maxX, p[0]);
		uMap[p[1]].emplace(p[0]);
	}

	double midX = (double)(maxX + minX) / 2;

	for (const auto &p : points) {
		double diff = midX - p[0];
		double reflectX = midX + diff;
		if (uMap[p[1]].find(reflectX) == uMap[p[1]].end()) {
			return false;
		}
	}
	return true;
}
