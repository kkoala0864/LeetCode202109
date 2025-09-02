#include <Solution.h>

int Solution::numberOfPairs(vector<vector<int>>& points) {
	map<int, set<int>> xa;

	for (const auto& p : points) {
		xa[p[0]].emplace(p[1]);
	}

	int result = 0;
	int size = points.size();
	for (int i = 0 ; i < size ; ++i) {
		for (int j = 0 ; j < size ; ++j) {
			if (i == j) continue;
			if ((points[i][0] > points[j][0]) || (points[i][1] < points[j][1])) continue;
			auto xIter = xa.lower_bound(points[i][0]);
			int cnt = 0;
			for (; xIter != xa.end() && xIter->first <= points[j][0] && cnt == 0 ; ++xIter) {
				auto yi = xIter->second.upper_bound(points[i][1]);
				if (yi == xIter->second.begin()) continue;
				--yi;
				if (xIter->first == points[i][0] && *yi == points[i][1]) {
					if (yi == xIter->second.begin()) continue;
					--yi;
				}
				auto yj = xIter->second.lower_bound(points[j][1]);
				if (yj == xIter->second.end()) continue;
				if (xIter->first == points[j][0] && *yj == points[j][1]) ++yj;
				if (yj == xIter->second.end()) continue;
				if (*yj <= *yi) ++cnt;
			}
			if (cnt == 0) ++result;
		}
	}
	return result;
}
