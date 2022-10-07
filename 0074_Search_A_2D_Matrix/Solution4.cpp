#include <Solution.h>
#include <iostream>

bool Solution::searchMatrix4(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();

	int l = 0, r = m * n - 1;
	int mid = 0;
	while (l < r) {
		mid = l + ((r-l) >> 1);
		if (matrix[mid/n][mid%n] < target) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return matrix[l/n][l%n] == target;
}

