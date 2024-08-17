#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::pair;
using std::max;

long long Solution::maxPoints(vector<vector<int>>& points) {
	int m = points.size();
	int n = points[0].size();

	vector<long long> cur, last;
	for (const auto& v : points[0]) last.emplace_back(v);

	for (int i = 1 ; i < m ; ++i) {
		long long local = 0;
		for (int j = 0 ; j < n ; ++j) { //cur
			long long v = 0;
			for (int k = 0 ; k < n ; ++k) { //last
				v = max(v, (long long)last[k] - (long long)abs(j - k));
			}
			cur.emplace_back((long long)points[i][j] + v);
		}
		last = move(cur);
	}
	long long result = 0;
	for (const auto& v : last) {
		result = max(result, v);
	}
	return result;
}
