#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>

using std::unordered_map;
using std::unordered_set;
using std::sort;
using std::min;

int Solution::minAreaRect(vector<vector<int>>& points) {
	unordered_map<int, unordered_set<int>> m;
	for (const auto& p : points) {
		m[p[0]].emplace(p[1]);
	}
	sort(points.begin(), points.end());

	int result = INT_MAX;
	for (int i = 0 ; i < points.size() ; ++i) {
		for (int j = i + 1 ; j < points.size() ; ++j) {
			if (points[j][1] >= points[i][1]) continue;
			if (m[points[j][0]].count(points[i][1]) == 0 || m[points[i][0]].count(points[j][1]) == 0) continue;
			result = min(result, (points[j][0] - points[i][0]) * (points[i][1] - points[j][1]));
		}
	}
	return result == INT_MAX ? 0 : result;
}
