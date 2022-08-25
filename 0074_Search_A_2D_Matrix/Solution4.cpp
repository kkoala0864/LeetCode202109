#include <Solution.h>
#include <iostream>

bool Solution::searchMatrix4(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	int l = 0, r = m * n - 1;
	int mid = 0;

	while (l <= r) {
		mid = (l + r) >> 1;
		int i = mid / n;
		int j = mid % n;
		if (matrix[i][j] == target) return true;
		else if (matrix[i][j] < target) l = mid + 1;
		else r = mid - 1;
	}
	return false;
}

