#include <Solution.h>
#include <iostream>

using std::swap;

void Solution::rotate2(vector<vector<int>>& matrix) {
	int m = matrix.size();

	for (int i = 0 ; i < m ; ++i) {
		int start = 0, end = m - 1;
		while (start < end) {
			swap(matrix[i][start++], matrix[i][end--]);
		}
	}
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < m ; ++j) {
			if ((i+j) == m-1) break;
			swap(matrix[i][j], matrix[m-j-1][m-i-1]);
		}
	}
}
