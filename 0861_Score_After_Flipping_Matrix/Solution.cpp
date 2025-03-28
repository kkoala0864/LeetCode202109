#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::matrixScore(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();

	for (int i = 0; i < m; ++i) {
		int rv0 = 0;
		int rv1 = 0;
		int base = 1;
		for (int j = n - 1; j >= 0; --j) {
			if (grid[i][j] == 0)
				rv0 += base;
			else
				rv1 += base;
			base = base << 1;
		}
		if (rv0 > rv1) {
			for (int j = 0; j < n; ++j) {
				grid[i][j] = grid[i][j] ? 0 : 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (grid[j][i] == 0)
				++cnt;
		}
		if (cnt > (m - cnt)) {
			for (int j = 0; j < m; ++j) {
				grid[j][i] = grid[j][i] ? 0 : 1;
			}
		}
	}
	int result = 0;
	for (int i = m - 1; i >= 0; --i) {
		int base = 1;
		for (int j = n - 1; j >= 0; --j) {
			if (grid[i][j] == 1)
				result += base;
			base = base << 1;
		}
	}
	return result;
}
