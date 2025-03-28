#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

long long Solution::maxMatrixSum(vector<vector<int>> &matrix) {
	long long result = 0;

	int minV = INT_MAX;
	int nCnt = 0;

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			result += (long long)abs(matrix[i][j]);
			minV = min(minV, abs(matrix[i][j]));
			if (matrix[i][j] < 0)
				++nCnt;
		}
	}
	return nCnt & 1 ? result - (2 * minV) : result;
}
