#include <Solution.h>
#include <iostream>

bool dfs2(vector<vector<int>>& dis, vector<int>& color, int idx, int c) {
	if (color[idx] != 0) return color[idx] == c;
	color[idx] = c;

	for (const auto& n : dis[idx]) {
		if (!dfs2(dis, color, n, c == 1 ? 2 : 1)) return false;
	}
	return true;
}


bool Solution::possibleBipartition2(int n, vector<vector<int>>& dislikes) {
	vector<vector<int>> dis(n, vector<int>());

	for (const auto& d : dislikes) {
		dis[d[0]-1].emplace_back(d[1]-1);
		dis[d[1]-1].emplace_back(d[0]-1);
	}

	vector<int> color(n, 0);
	for (int i = 0 ; i < n ; ++i) {
		if (color[i] != 0) continue;
		if (!dfs2(dis, color, i, 1)) return false;
	}
	return true;
}
