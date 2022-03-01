#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::unordered_map;
using std::unordered_set;
using std::sort;

bool Solution::isReflected2(vector<vector<int>>& points) {
	unordered_map<int, unordered_set<int>> uMap;

	for (const auto& iter : points) uMap[iter[1]].emplace(iter[0]);

	double gX = 100000001;
	for (const auto& iter : uMap) {
		vector<int> y;
		for (const auto& iter : iter.second) y.emplace_back(iter);
		sort(y.begin(), y.end());
		int start = 1, end = y.size() - 2;
		if (gX == 100000001) gX = ((double)y[0] + (double)y.back()) / 2;
		else if (gX != ((double)y[0] + (double)y.back()) / 2) return false;
		while (start <= end) {
			double local = ((double)y[start++] + (double)y[end--]) / 2;
			if (local != gX) return false;
		}
	}
	return true;
}
