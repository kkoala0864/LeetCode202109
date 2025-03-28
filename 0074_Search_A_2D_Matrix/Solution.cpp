#include <Solution.h>
#include <iostream>

bool Solution::searchMatrix(vector<vector<int>> &matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	int start = 0;
	int end = m * n - 1;
	int mid = 0;

	while (start <= end) {
		int mid = (end + start) / 2;
		int midx = mid / n;
		int midy = mid % n;
		int midVal = matrix[midx][midy];
		if (midVal == target)
			return true;
		else if (midVal > target) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return false;
}
