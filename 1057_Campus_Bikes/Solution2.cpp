#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::greater;
using std::pair;
using std::priority_queue;

vector<int> Solution::assignBikes2(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
	vector<bool> take(bikes.size(), false);
	vector<vector<pair<int, int>>> v(2000, vector<pair<int, int>>());

	vector<int> result(workers.size(), -1);
	for (int i = 0; i < workers.size(); ++i) {
		for (int j = 0; j < bikes.size(); ++j) {
			int distance = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
			v[distance].emplace_back(pair<int, int>(i, j));
		}
	}

	for (const auto &e : v) {
		if (e.empty())
			continue;
		for (const auto &p : e) {
			if (result[p.first] != -1)
				continue;
			if (take[p.second])
				continue;

			result[p.first] = p.second;
			take[p.second] = true;
		}
	}

	return result;
}
