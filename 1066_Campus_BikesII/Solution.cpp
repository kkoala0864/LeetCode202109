#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::min;

int dfs(vector<vector<int>>& workers, int wIdx, vector<vector<int>>& bikes,
		int bbit, vector<unordered_map<int, int>>& cache) {

	if (wIdx == workers.size()) return 0;

	if (cache[wIdx].count(bbit) > 0) return cache[wIdx][bbit];

	int cur = INT_MAX;
	for (int i = 0 ; i < bikes.size() ; ++i) {
		if (bbit & 1 << i) continue;
		int distance = abs(bikes[i][0] - workers[wIdx][0]) + abs(bikes[i][1] - workers[wIdx][1]);
		cur = min(cur, distance + dfs(workers, wIdx + 1, bikes, bbit | (1 << i), cache));
	}
	cache[wIdx][bbit] = cur;
	return cur;
}

int Solution::assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
	vector<unordered_map<int, int>> cache(workers.size(), unordered_map<int, int>());
	return dfs(workers, 0, bikes, 0, cache);
}

