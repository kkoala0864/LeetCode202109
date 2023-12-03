#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minTimeToVisitAllPoints(vector<vector<int>>& points) {
	int result = 0;
	for (int i = 1 ; i < points.size() ; ++i) {
		int x = abs(points[i][0] - points[i-1][0]);
		int y = abs(points[i][1] - points[i-1][1]);
		int dia = min(x, y);
		result += (x + y - dia);
	}
	return result;
}
