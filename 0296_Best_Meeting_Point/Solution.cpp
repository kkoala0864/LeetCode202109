#include <Solution.h>
#include <iostream>

using std::pair;

int min1D(vector<int>& vecs) {
	int result = 0;
	int i = 0, j = vecs.size() - 1;
	while (i < j) result += (vecs[j--] - vecs[i++]);
	return result;
}

int Solution::minTotalDistance(vector<vector<int>>& grid) {
	vector<int> rows, cols;
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == 1) {
				rows.emplace_back(i);
			}
		}
	}
	for (int j = 0 ; j < grid[0].size() ; ++j) {
		for (int i = 0 ; i < grid.size() ; ++i) {
			if (grid[i][j] == 1) {
				cols.emplace_back(j);
			}
		}
	}
	return min1D(rows) + min1D(cols);
}
