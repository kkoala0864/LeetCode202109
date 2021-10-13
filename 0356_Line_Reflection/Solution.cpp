#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using std::min;
using std::max;
using std::pair;
using std::map;

bool Solution::isReflected(vector<vector<int>>& points) {
	int maxVal = INT_MIN;
	int minVal = INT_MAX;
	map<pair<int,int>, bool> uMap;

	for (const auto& pt : points) {
		maxVal = max(maxVal, pt[0]);
		minVal = min(minVal, pt[0]);
		uMap[pair<int,int>(pt[0], pt[1])] = true;
	}

	double xAxis = ((double)maxVal + (double)minVal) / 2;

	for (int i = 0 ; i < points.size() ; ++i) {
		int x = points[i][0];
		int y = points[i][1];
		int rx = (2 * xAxis) - x;
		if (!uMap[pair<int, int>(rx, y)]) return false;
	}
	return true;
}
