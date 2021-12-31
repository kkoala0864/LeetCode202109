#include <Solution.h>
#include <iostream>

using std::swap;

void Solution::rotate3(vector<vector<int>>& matrix) {
	for (int i = 0 ; i < matrix.size() ; ++i) {
		for (int j = i ; j < matrix.size() ; ++j) {
			if (i != j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}

	for (int i = 0 ; i < matrix.size() ; ++i) {
		int start = 0 , end = matrix[0].size() - 1;
		while (start <= end) {
			swap(matrix[i][start], matrix[i][end]);
			++start;
			--end;
		}
	}
}
