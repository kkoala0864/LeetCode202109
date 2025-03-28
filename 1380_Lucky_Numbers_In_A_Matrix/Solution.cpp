#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

vector<int> Solution::luckyNumbers(vector<vector<int>> &matrix) {
	vector<int> row(matrix.size(), INT_MAX);
	vector<int> colums(matrix[0].size(), INT_MIN);

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			row[i] = min(row[i], matrix[i][j]);
			colums[j] = max(colums[j], matrix[i][j]);
		}
	}
	vector<int> result;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (row[i] == colums[j])
				result.emplace_back(row[i]);
		}
	}
	return result;
}
