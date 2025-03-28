#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int dfs(int prev, int cur, unordered_map<int, vector<int>> &connect, const int &seats, long long &result) {
	int childCnt = 0;
	for (const auto &n : connect[cur]) {
		if (n == prev)
			continue;
		childCnt += dfs(cur, n, connect, seats, result);
	}

	if (cur != 0) {
		result += (childCnt + 1) / seats;
		if ((childCnt + 1) % seats > 0)
			result += 1;
	}
	return childCnt + 1;
}

long long Solution::minimumFuelCost(vector<vector<int>> &roads, int seats) {
	unordered_map<int, vector<int>> connect;

	for (const auto &r : roads) {
		connect[r[0]].emplace_back(r[1]);
		connect[r[1]].emplace_back(r[0]);
	}

	long long result = 0;
	dfs(-1, 0, connect, seats, result);

	return result;
}
