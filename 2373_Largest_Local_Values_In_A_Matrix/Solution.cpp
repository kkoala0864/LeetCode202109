#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

vector<vector<int>> Solution::largestLocal(vector<vector<int>>& grid) {
	int n = grid.size();

	vector<vector<int>> m(n-2, vector<int>(n-2, INT_MIN));

	for (int i = 1 ; i < (n - 1) ; ++i) {
		for (int j = 1 ; j < (n - 1) ; ++j) {
			for (int x = i - 1 ; x < (i + 2) ; ++x) {
				for (int y = j - 1 ; y < (j + 2) ; ++y) {
					m[i-1][j-1] = max(grid[x][y], m[i-1][j-1]);
				}
			}
		}
	}

	return m;
}
