#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs2(const vector<vector<int>>& stones, int cur,
		unordered_map<int, vector<int>>& row,
		unordered_map<int, vector<int>>& col,
		vector<bool>& removed) {

	vector<int> axis = stones[cur];
	for (const auto& iter : row[axis[0]]) {
		if (removed[iter]) continue;
		removed[iter] = true;
		dfs2(stones, iter, row, col, removed);
	}
	for (const auto& iter : col[axis[1]]) {
		if (removed[iter]) continue;
		removed[iter] = true;
		dfs2(stones, iter, row, col, removed);
	}
}

int Solution::removeStones2(vector<vector<int>>& stones) {
	unordered_map<int, vector<int>> row, col;
	vector<bool> removed(stones.size(), false);

	int result = 0;
	for (int i = 0 ; i < stones.size() ; ++i) {
		row[stones[i][0]].emplace_back(i);
		col[stones[i][1]].emplace_back(i);
	}
	for (int i = 0 ; i < stones.size() ; ++i) {
		if (removed[i]) continue;
		++result;
		removed[i] = true;
		dfs2(stones, i, row, col, removed);
	}
	return stones.size() - result;
}
