#include <Solution.h>
#include <iostream>

bool Solution::searchMatrix3(vector<vector<int>> &matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	int i = 0, j = n - 1;
	while (i < m && j >= 0) {
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] < target)
			++i;
		else if (matrix[i][j] > target)
			--j;
	}
	return false;
}
