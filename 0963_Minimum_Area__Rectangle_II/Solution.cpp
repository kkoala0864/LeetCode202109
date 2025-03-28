#include <Solution.h>
#include <iostream>
#include <float.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using std::min;
using std::unordered_map;
using std::unordered_set;

double Solution::minAreaFreeRect(vector<vector<int>> &points) {
	double result = 0;
	unordered_map<int, unordered_set<int>> m;
	for (const auto &v : points)
		m[v[0]].emplace(v[1]);

	for (int i = 0; i < points.size(); ++i) {
		int ix = points[i][0];
		int iy = points[i][1];

		for (int j = i + 1; j < points.size(); ++j) {
			int jx = points[j][0];
			int jy = points[j][1];

			for (int k = j + 1; k < points.size(); ++k) {
				int kx = points[k][0];
				int ky = points[k][1];

				if (((jx - ix) * (kx - ix) + (jy - iy) * (ky - iy)) != 0)
					continue;

				int wx = kx + jx - ix;
				int wy = ky + jy - iy;

				if (m[wx].count(wy) == 0)
					continue;
				double area = sqrt((jx - ix) * (jx - ix) + (jy - iy) * (jy - iy)) * sqrt((kx - ix) * (kx - ix) + (ky - iy) * (ky - iy));

				if (result == 0) {
					result = area;
				} else {
					result = min(result, area);
				}
			}
		}
	}
	return result;
}
