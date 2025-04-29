#include <Solution.h>
#include <iostream>
#include <unordered_map>

vector<vector<int>> Solution::multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
	vector<vector<int>> result(mat1.size(), vector<int>(mat2[0].size()));
	unordered_map<int, unordered_map<int, int>> xa;

	for (int i = 0 ; i < mat2.size() ; ++i) {
		for (int j = 0 ; j < mat2[0].size() ; ++j) {
			if (mat2[i][j] == 0) continue;
			xa[i][j] = mat2[i][j];
		}
	}

	for (int i = 0 ; i < mat1.size() ; ++i) {
		for (int j = 0 ; j < mat1[0].size() ; ++j) {
			if (mat1[i][j] == 0) continue;
			if (xa.count(j)) {
				for (const auto& e : xa[j]) {
					result[i][e.first] += (mat1[i][j] * e.second);
				}
			}
		}
	}
	return result;
}

