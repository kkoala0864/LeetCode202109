#include <Solution.h>
#include <iostream>

vector<int> axis = {1, 0, -1, 0, 1};

void dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j, bool& result) {
	g2[i][j] = 0;
	result &= (g1[i][j] == 1);

	for (int k = 0 ; k < 4 ; ++k) {
		int nx = i + axis[k];
		int ny = j + axis[k+1];

		if (nx < 0 || ny < 0 || nx >= g1.size() || ny >= g1[0].size() || g2[nx][ny] == 0) continue;

		dfs(g1, g2, nx, ny, result);
	}
}

int Solution::countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
	int result = 0;
	for (int i = 0 ; i < grid1.size() ; ++i) {
		for (int j = 0 ; j < grid1[0].size() ; ++j) {
			if (grid2[i][j] == 1) {
				bool local = true;
				dfs(grid1, grid2, i, j, local);
				if (local) ++result;
			}
		}
	}
	return result;

}
