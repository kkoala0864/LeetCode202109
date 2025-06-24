#include <Solution.h>

int Solution::maxPoints(vector<vector<int>> &points) {
	unordered_map<int, int> xs, ys;
	unordered_map<double, unordered_map<double, unordered_set<int>>> slopes;

	int result = 0;
	for (int i = 0 ; i < points.size() ; ++i) {
		++xs[points[i][0]];
		++ys[points[i][1]];
		result = max({result, xs[points[i][0]], ys[points[i][1]]});
		for (int j = i + 1 ; j < points.size() ; ++j) {
			if ((points[i][0] == points[j][0]) || (points[i][1] == points[j][1])) continue;
			double slope = ((points[j][1] - points[i][1]) * 1.0) / (points[j][0] - points[i][0]);
			double intercept = points[i][1] - slope * points[i][0];
			slopes[slope][intercept].emplace(i);
			slopes[slope][intercept].emplace(j);
		}
	}
	for (const auto& e : slopes) {
		for (const auto& d : e.second) {
			result = max(result, (int)d.second.size());
		}
	}
	return result;
}
