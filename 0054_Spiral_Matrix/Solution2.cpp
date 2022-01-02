#include <Solution.h>
#include <iostream>

vector<int> Solution::spiralOrder2(vector<vector<int>>& matrix) {
	int rLow = 0, rHigh = matrix.size();
	int cLow = 0, cHigh = matrix[0].size();
	int count = rHigh * cHigh;
	vector<int> result;

	int x = 0, y = 0;
	while (true) {
		while (y < cHigh) {
			result.emplace_back(matrix[x][y++]);
			--count;
		}
		if (count == 0) break;
		++rLow;
		++x;
		--y;
		while (x < rHigh) {
			result.emplace_back(matrix[x++][y]);
			--count;
		}
		if (count == 0) break;
		--cHigh;
		--y;
		--x;
		while (y >= cLow) {
			result.emplace_back(matrix[x][y--]);
			--count;
		}
		if (count == 0) break;
		--rHigh;
		--x;
		++y;
		while (x >= rLow) {
			result.emplace_back(matrix[x--][y]);
			--count;
		}
		if (count == 0) break;
		++cLow;
		++y;
		++x;
	}
	return result;
}
