#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int Solution::maxPoints(vector<vector<int>>& points) {
	if (points.size() < 2) return points.size();

	int result = 0;
	for (int i = 0 ; i < points.size() ; ++i) {
		unordered_map<double, int> cnt;
		unordered_map<int, int> ver;
		unordered_map<int, int> hor;
		for (int j = 0 ; j < points.size() ; ++j) {
			if (i == j) continue;
			if (points[i][0] - points[j][0] == 0) {
				++ver[points[i][0]];
				result = max(result, ver[points[i][0]] + 1);
			} else if (points[i][1] == points[j][1]) {
				++hor[points[i][1]];
				result = max(result, hor[points[i][1]] + 1);
			} else {
				double val = (double)(points[i][1] - points[j][1]) / (double)(points[i][0] - points[j][0]);
				++cnt[val];
				result = max(result, cnt[val] + 1);
			}
		}
	}
	return result;
}
