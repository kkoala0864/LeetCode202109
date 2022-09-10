#include <Solution.h>
#include <iostream>

vector<int> axis4 = {1, 0, -1, 0, 1};

void dfs4(vector<vector<int>>& heights, vector<vector<int>>& flow, int x, int y, int mark) {
	if (flow[x][y] == mark || flow[x][y] == 3) return;

	flow[x][y] += mark;

	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + axis4[i];
		int ny = y + axis4[i+1];
		if (nx < 0 || ny < 0 || nx >= flow.size() || ny >= flow[0].size() ||
				heights[x][y] > heights[nx][ny] || flow[nx][ny] == mark || flow[nx][ny] == 3) continue;
		dfs4(heights, flow, nx, ny, mark);
	}
}

vector<vector<int>> Solution::pacificAtlantic4(vector<vector<int>>& heights) {
	int m = heights.size();
	int n = heights[0].size();

	vector<vector<int>> flow(m, vector<int>(n, 0));
	for (int i = 0 ; i < m ; ++i) {
		dfs4(heights, flow, i, 0, 1);
		dfs4(heights, flow, i, n-1, 2);
	}
	for (int j = 0 ; j < n ; ++j) {
		dfs4(heights, flow, 0, j, 1);
		dfs4(heights, flow, m-1, j, 2);
	}
	vector<vector<int>> result;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (flow[i][j] == 3) result.push_back({i, j});
		}
	}
	return result;
}
