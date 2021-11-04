#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
vector<vector<int>> Solution::generateMatrix(int n) {
	int totalSize = n * n;
	int x = 0, y = 0;
	int cnt = 1, xUpB = n, xLowB = 0, yUpB = n, yLowB = 0;
	vector<vector<int>> result(n, vector<int>(n, 0));
	while (cnt <= totalSize) {
		while (y < yUpB) {
			result[x][y] = cnt;
			++cnt;
			++y;
		}
		--y;
		++x;
		++xLowB;
		while (x < xUpB) {
			result[x][y] = cnt;
			++cnt;
			++x;
		}
		--x;
		--y;
		--yUpB;
		while (y >= yLowB) {
			result[x][y] = cnt;
			++cnt;
			--y;
		}
		++y;
		--x;
		--xUpB;
		while (x >= xLowB) {
			result[x][y] = cnt;
			++cnt;
			--x;
		}
		++x;
		++y;
		++yLowB;
	}
	return result;
}
