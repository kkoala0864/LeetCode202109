#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::pair;

int Solution::maxKilledEnemies(vector<vector<char>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> row(m, vector<int>(n, 0));
	vector<vector<int>> col(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 'E')
				++cnt;
			else if (grid[i][j] == 'W')
				cnt = 0;
			row[i][j] += cnt;
		}
		cnt = 0;
		for (int j = n - 1; j >= 0; --j) {
			if (j < n - 1)
				row[i][j] += cnt;
			if (grid[i][j] == 'E')
				++cnt;
			else if (grid[i][j] == 'W')
				cnt = 0;
		}
	}
	for (int j = 0; j < n; ++j) {
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			if (grid[i][j] == 'E')
				++cnt;
			else if (grid[i][j] == 'W')
				cnt = 0;
			col[i][j] += cnt;
		}
		cnt = 0;
		for (int i = m - 1; i >= 0; --i) {
			if (i < m - 1)
				col[i][j] += cnt;
			if (grid[i][j] == 'E')
				++cnt;
			else if (grid[i][j] == 'W')
				cnt = 0;
		}
	}
	int result = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] != '0')
				continue;
			result = max(result, col[i][j] + row[i][j]);
		}
	}
	return result;
}
