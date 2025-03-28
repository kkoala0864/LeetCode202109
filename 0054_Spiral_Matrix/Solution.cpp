#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

vector<int> Solution::spiralOrder(vector<vector<int>> &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int size = m * n;
	vector<int> result;
	int x_lower = 0, x_upper = m, y_lower = 0, y_upper = n;
	int x = 0, y = 0, count = 0;

	while (true) {
		for (; y < y_upper; ++y) {
			result.emplace_back(matrix[x][y]);
			++count;
		}
		if (count >= size)
			break;
		--y_upper;
		--y;
		++x;
		for (; x < x_upper; ++x) {
			result.emplace_back(matrix[x][y]);
			++count;
		}
		if (count >= size)
			break;
		--x_upper;
		--x;
		--y;
		for (; y >= y_lower; --y) {
			result.emplace_back(matrix[x][y]);
			++count;
		}
		if (count >= size)
			break;
		++y_lower;
		++x_lower;
		++y;
		--x;
		for (; x >= x_lower; --x) {
			result.emplace_back(matrix[x][y]);
			++count;
		}
		if (count >= size)
			break;
		++x;
		++y;
	}
	return result;
}
