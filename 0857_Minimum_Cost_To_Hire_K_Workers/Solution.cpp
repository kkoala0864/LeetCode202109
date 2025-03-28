#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <float.h>
#include <queue>

using std::min;
using std::pair;
using std::priority_queue;
using std::sort;

double Solution::mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
	vector<pair<double, double>> wagePerQ;

	for (int i = 0; i < quality.size(); ++i) {
		wagePerQ.emplace_back(pair<double, double>((double)wage[i] / (double)quality[i], (double)quality[i]));
	}

	sort(wagePerQ.begin(), wagePerQ.end());
	priority_queue<double> pq;
	double cost = DBL_MAX;
	double local = 0;
	for (int i = 0; i < wagePerQ.size(); ++i) {
		local += wagePerQ[i].second;
		pq.emplace(wagePerQ[i].second);
		if (pq.size() > k)
			local -= pq.top(), pq.pop();
		if (pq.size() == k)
			cost = min(cost, wagePerQ[i].first * local);
	}
	return cost;
}
