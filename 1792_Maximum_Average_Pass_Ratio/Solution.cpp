#include <Solution.h>

double Solution::maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
	priority_queue<pair<double, int>> pq;

	for (int i = 0 ; i < classes.size() ; ++i) {
		if (classes[i][0] == classes[i][1]) continue;
		double r = (classes[i][0] * 1.0) / classes[i][1];
		double nr = ((classes[i][0] + 1) * 1.0) / (classes[i][1] + 1);
		pq.emplace(pair<double, int>(nr - r, i));
	}
	if (pq.empty()) return 1;

	while (extraStudents-- > 0) {
		int ci = pq.top().second;
		pq.pop();

		++classes[ci][0];
		++classes[ci][1];
		double r = (classes[ci][0] * 1.0) / classes[ci][1];
		double nr = ((classes[ci][0] + 1) * 1.0) / (classes[ci][1] + 1);
		pq.emplace(pair<double, int>(nr - r, ci));
	}

	double sum = 0;
	for (const auto& c : classes) {
		double r = (c[0] * 1.0) / c[1];
		sum += r;
	}
	return sum / classes.size();

}
