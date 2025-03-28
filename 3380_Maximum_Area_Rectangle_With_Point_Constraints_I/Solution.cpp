#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>

using std::max;
using std::unordered_map;
using std::unordered_set;
using std::pair;
using std::cout;
using std::endl;

int Solution::maxRectangleArea(vector<vector<int>>& points) {
	unordered_map<int, unordered_set<int>> xa;

	for (const auto& p : points) {
		xa[p[0]].emplace(p[1]);
	}

	sort(points.begin(), points.end());
	vector<vector<int>> candidate;

	for (int i = 0 ; i < points.size() ; ++i) {
		for (int j = i + 1 ; j < points.size() ; ++j) {
			if (points[j][0] <= points[i][0] || points[j][1] <= points[i][1]) continue;
			if (xa[points[j][0]].count(points[i][1]) == 0 || xa[points[i][0]].count(points[j][1]) == 0) continue;
			int area = (points[j][0] - points[i][0]) * (points[j][1] - points[i][1]);
			candidate.emplace_back(vector<int>({area, i, j}));
		}
	}
	int result = -1;
	for (const auto& c : candidate) {
		int x1 = points[c[1]][0];
		int y1 = points[c[1]][1];
		int x2 = points[c[2]][0];
		int y2 = points[c[2]][1];
		int i = 0;
		for (; i < points.size() ; ++i) {
			if (i == c[1] || i == c[2]) continue;
			if ((points[i][0] == x1 && points[i][1] == y2) || (points[i][0] == x2 && points[i][1] == y1)) continue;
			if ((x1 <= points[i][0] && points[i][0] <= x2) && (y1 <= points[i][1] && points[i][1] <= y2)) break;
		}
		if (i < points.size()) continue;
		result = max(result, c[0]);
	}
	return result;
}
