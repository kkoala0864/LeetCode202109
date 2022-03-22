#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
	vector<vector<int>> result(mat1.size(), vector<int>(mat2[0].size(), 0));

	for (int i = 0 ; i < mat1.size() ; ++i) {
		for (int k = 0 ; k < mat1[0].size() ; ++k) {
			for (int j = 0 ; j < mat2[0].size() ; ++j) {
				result[i][j] += (mat1[i][k] * mat2[k][j]);
			}
		}
	}
	return result;
}
