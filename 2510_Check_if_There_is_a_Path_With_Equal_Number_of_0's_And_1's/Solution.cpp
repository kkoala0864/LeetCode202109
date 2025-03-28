#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

bool Solution::isThereAPath(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	int mid = m + n - 1;
	if (mid & 1)
		return false;
	mid = mid >> 1;
	vector<vector<vector<bool>>> offset(m, vector<vector<bool>>(n, vector<bool>(mid + 1, false)));
	offset[0][0][grid[0][0]] = true;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i > 0) {
				for (int k = 0; k <= mid; ++k) {
					if (offset[i - 1][j][k] && (k + grid[i][j]) <= mid) {
						offset[i][j][k + grid[i][j]] = true;
					}
				}
			}
			if (j > 0) {
				for (int k = 0; k <= mid; ++k) {
					if (offset[i][j - 1][k] && (k + grid[i][j]) <= mid) {
						offset[i][j][k + grid[i][j]] = true;
					}
				}
			}
		}
	}

	return offset[m - 1][n - 1][mid];
}
