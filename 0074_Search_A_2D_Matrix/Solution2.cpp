#include <Solution.h>
#include <iostream>

bool Solution::searchMatrix2(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();

	int start = 0, end = m * n - 1;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		int r = mid / n;
		int c = mid % n;
		if (matrix[r][c] == target) return true;
		else if (matrix[r][c] > target) end = mid - 1;
		else start = mid + 1;
	}
	return false;
}

