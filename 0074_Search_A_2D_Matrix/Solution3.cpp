#include <Solution.h>
#include <iostream>

bool Solution::searchMatrix3(vector<vector<int>> &matrix, int target) {
	int start = 0, end = matrix.size() * matrix[0].size() - 1;

	int mid = 0;
	int row = 0, col = 0;
	while (start <= end) {
		mid = (end - start) / 2 + start;
		row = mid / matrix[0].size();
		col = mid % matrix[0].size();
		if (matrix[row][col] == target)
			return true;
		else if (matrix[row][col] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
}
