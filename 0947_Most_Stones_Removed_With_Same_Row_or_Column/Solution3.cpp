#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs3(vector<vector<int>>& stones, int i, unordered_map<int, vector<int>>& col, unordered_map<int, vector<int>>& row, vector<bool>& fix) {
	for (const auto& xi : row[stones[i][0]]) {
		if (fix[xi]) continue;
		fix[xi] = true;
		dfs3(stones, xi, col, row, fix);
	}

	for (const auto& yi : col[stones[i][1]]) {
		if (fix[yi]) continue;
		fix[yi] = true;
		dfs3(stones, yi, col, row, fix);
	}
}

int Solution::removeStones3(vector<vector<int>>& stones) {
	int size = stones.size();
	unordered_map<int, vector<int>> col, row;
	vector<bool> fix(size, false);

	for (int i = 0 ; i < size ; ++i) {
		row[stones[i][0]].emplace_back(i);
		col[stones[i][1]].emplace_back(i);
	}

	int take = 0;

	for (int i = 0 ; i < size ; ++i) {
		if (fix[i]) continue;
		++take;
		fix[i] = true;
		dfs3(stones, i, col, row, fix);
	}
	return stones.size() - take;
}
