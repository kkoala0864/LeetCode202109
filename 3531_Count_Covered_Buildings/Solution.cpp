#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <set>

int Solution::countCoveredBuildings(int n, vector<vector<int>>& buildings) {
	unordered_map<int, set<int>> xa, ya;

	for (const auto& b : buildings) {
		xa[b[0]].emplace(b[1]);
		ya[b[1]].emplace(b[0]);
	}

	int result = 0;
	for (const auto& b : buildings) {
		auto iter = xa[b[0]].lower_bound(b[1]);
		if (iter == xa[b[0]].begin() || next(iter) == xa[b[0]].end()) continue;
		iter = ya[b[1]].lower_bound(b[0]);
		if (iter == ya[b[1]].begin() || next(iter) == ya[b[1]].end()) continue;
		++result;
	}
	return result;
}

