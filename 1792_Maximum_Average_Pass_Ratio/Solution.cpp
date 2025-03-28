#include <Solution.h>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::pair;
using std::priority_queue;

double Solution::maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
	priority_queue<pair<double, int>> pq;
	double size = classes.size();

	for (int i = 0; i < classes.size(); ++i) {
		if (classes[i][0] == classes[i][1])
			continue;
		double c = (double)classes[i][0] / (double)classes[i][1];
		double n = (double)(classes[i][0] + 1) / (double)(classes[i][1] + 1);
		pq.emplace(pair<double, int>(n - c, i));
	}
	if (pq.empty())
		return 1;

	while (extraStudents-- > 0) {
		int i = pq.top().second;
		int r = pq.top().first;
		pq.pop();

		++classes[i][0];
		++classes[i][1];
		double c = (double)classes[i][0] / (double)classes[i][1];
		double n = (double)(classes[i][0] + 1) / (double)(classes[i][1] + 1);
		pq.emplace(pair<double, int>(n - c, i));
	}
	double rSum = 0;
	for (const auto &v : classes) {
		rSum += ((double)v[0] / (double)v[1]);
	}
	return rSum / size;
}
