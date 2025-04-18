#include <Solution.h>
#include <iostream>

bool Solution::searchMatrix(vector<vector<int>> &matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();

	int x = 0, y = n - 1;
	while (x < m && y >= 0) {
		if (matrix[x][y] == target)
			return true;
		else if (matrix[x][y] > target)
			--y;
		else
			++x;
	}
	return false;
}
