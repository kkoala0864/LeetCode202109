#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::min;
using std::max;

int Solution::findMinArrowShots(vector<vector<int>>& points) {
	vector<vector<int>> overlap;
	sort(points.begin(), points.end());

	overlap.emplace_back(points[0]);
	int last = 0;
	for (int i = 1 ; i < points.size() ; ++i) {
		if (points[i][0] > overlap[last][1]) {
			overlap.emplace_back(points[i]);
			++last;
		} else {
			overlap[last][0] = max(overlap[last][0], points[i][0]);
			overlap[last][1] = min(overlap[last][1], points[i][1]);
		}
	}
	return overlap.size();
}
